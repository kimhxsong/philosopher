/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_routine_dining.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:27:35 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/11 16:34:12 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	do_sleeping_thinking(t_data *data)
{
	if (data->p.state != STATE_EATING)
		return ;
	data->p.state = STATE_SLEEPING;
	print_state(data);
	pthread_mutex_unlock(data->p.second);
	pthread_mutex_unlock(data->p.first);
	data->p.end_of_sleeping = data->p.time_of_thread + data->s->info[3];
	while (data->s->clock.current < data->p.end_of_sleeping)
		usleep(2000);
	if (data->p.state != STATE_SLEEPING)
		return ;
	data->p.time_of_thread = data->p.end_of_sleeping;
	data->p.state = STATE_THINKING;
	print_state(data);
}

static void	get_forks(t_data *data)
{
	if (data->p.state != STATE_THINKING)
		return ;
	pthread_mutex_lock(data->p.first);
	data->p.state = STATE_ONE_FORK;
	data->p.time_of_thread += (int)(data->s->clock.current
			- data->p.time_of_thread) / data->s->info[2] * data->s->info[2];
	print_state(data);
	pthread_mutex_lock(data->p.second);
}

static void	do_eating(t_data *data)
{	
	if (data->p.state != STATE_ONE_FORK)
		return ;
	data->p.state = STATE_EATING;
	data->p.time_of_thread += (int)(data->s->clock.current
			- data->p.time_of_thread) / data->s->info[2] * data->s->info[2];
	print_state(data);
	data->p.num_of_eat += 1;
	pthread_mutex_lock(&data->s->key.death);
	if (data->s->info[4] > 0 && data->p.num_of_eat == data->s->info[4])
		data->s->hungry -= 1;
	pthread_mutex_unlock(&data->s->key.death);
	data->p.time_to_die = data->p.time_of_thread + data->s->info[1];
	data->p.end_of_eating = data->p.time_of_thread + data->s->info[2];
	while (data->s->clock.current < data->p.end_of_eating)
		usleep(2000);
	data->p.time_of_thread = data->p.end_of_eating;
}

static void	do_ordering(t_data *data)
{
	if (data->p.id % 2 == 1)
		get_forks(data);
	pthread_mutex_unlock(&data->s->key.order);
}

void	*routine_dining(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	do_ordering(data);
	while (data->p.state != STATE_DIED && data->s->alive == data->s->info[0]
		&& data->s->hungry > 0)
	{
		get_forks(data);
		do_eating(data);
		do_sleeping_thinking(data);
	}
	pthread_mutex_unlock(data->p.second);
	pthread_mutex_unlock(data->p.first);
	pthread_mutex_lock(&data->s->key.death);
	data->s->alive -= 1;
	pthread_mutex_unlock(&data->s->key.death);
	return (NULL);
}
