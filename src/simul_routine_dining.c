/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_routine_dining.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:27:35 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/30 19:44:13 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int do_sleeping_thinking(t_data *data)
{
	if (data->p.state != STATE_EATING)
		return (0);
	data->p.state = STATE_SLEEPING;
	if (print_state(data))
		return (-1);
	//if (data->s->info[4] > 0 && data->p.num_of_eat > data->s->info[4])
	//	data->p.state = STATE_FULL;
	data->p.end_of_sleeping = data->p.time_of_thread + data->s->info[3];
	while (data->s->clock.current < data->p.end_of_sleeping)
		usleep(200);
	data->p.time_of_thread = data->p.end_of_sleeping;
	data->p.state = STATE_THINKING;
	if (print_state(data))
		return (-1);
	return (0);
}

static int get_forks(t_data *data)
{
	if (data->p.state != STATE_THINKING)
		return (0);
	pthread_mutex_lock(&data->s->forks[data->p.first]);
	data->p.state = STATE_ONE_FORK;
	data->p.time_of_thread += ((data->s->clock.current
		- data->p.time_of_thread) / data->s->info[2]) * data->s->info[2];
	if (print_state(data))
		return (-1);
	pthread_mutex_lock(&data->s->forks[data->p.second]);
	return (0);
}

static int	do_eating(t_data *data)
{	
	if (data->p.state != STATE_ONE_FORK)
		return (0);
	data->p.state = STATE_EATING;
	data->p.time_of_thread += ((data->s->clock.current
		- data->p.time_of_thread) / data->s->info[2]) * data->s->info[2];
	if (print_state(data))
		return (-1);
	data->p.time_to_die = data->p.time_of_thread + data->s->info[1];
	data->p.end_of_eating = data->p.time_of_thread + data->s->info[2];
	data->p.num_of_eat += 1;
	while(data->s->clock.current < data->p.end_of_eating)
		usleep(200);
	data->p.time_of_thread = data->p.end_of_eating;
	pthread_mutex_unlock(&data->s->forks[data->p.second]);
	pthread_mutex_unlock(&data->s->forks[data->p.first]);
	return (0);
}

static int	do_ordering(t_data *data)
{
	if (data->p.id % 2 == 1)
	{
		if (get_forks(data))
			return (-1);
	}
	pthread_mutex_unlock(&data->s->key.order);
	return (0);
}

void	*routine_dining(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	if (do_ordering(data))
		return (NULL);
	while (!data->s->is_finished)
	{
		if (get_forks(data) || do_eating(data) || do_sleeping_thinking(data))
			break ;
	}
	return (NULL);
}
