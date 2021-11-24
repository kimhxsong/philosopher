/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_routine_dining.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:27:35 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/24 20:14:30 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_forks_and_do_eating(t_data *data)
{
	pthread_mutex_lock(&data->s->fork[data->p.first]);
	data->p.state = STATE_ONE_FORK;
	data->p.time_of_thread += (data->s->clock.current - data->p.time_of_thread)
		/ data->s->info.time_of_eating * data->s->info.time_of_eating;
	if (print_state(data) == FAIL)
		return (FAIL);
	pthread_mutex_lock(&data->s->fork[data->p.second]);
	data->p.state = STATE_EATING;
	data->p.time_of_thread += (data->s->clock.current - data->p.time_of_thread)
		/ data->s->info.time_of_eating * data->s->info.time_of_eating;
	if (print_state(data) == FAIL)
		return (FAIL);
	data->p.time_to_die = data->p.time_of_thread + data->s->info.time_to_die;
	data->p.end_of_eating = data->p.time_of_thread
		+ data->s->info.time_of_eating;
	data->p.num_of_eat += 1;
	while(data->s->clock.current < data->p.end_of_eating)
		usleep(200);
	data->p.time_of_thread = data->p.end_of_eating;
	return (SUCCESS);
}

static int do_sleeping_and_thinking(t_data *data)
{
	data->p.state = STATE_SLEEPING;
	if (print_state(data) == FAIL)
		return (FAIL);
	if (data->s->info.is_max_used == TRUE
		&& data->p.num_of_eat > data->s->info.max_eat_number)
		data->p.state = STATE_FULL;
	pthread_mutex_unlock(&data->s->fork[data->p.second]);
	pthread_mutex_unlock(&data->s->fork[data->p.first]);
	data->p.end_of_sleeping = data->p.time_of_thread
		+ data->s->info.time_of_sleeping;
	while (data->s->clock.current < data->p.end_of_sleeping)
		usleep(200);
	data->p.time_of_thread = data->p.end_of_sleeping;
	data->p.state == STATE_THINKING;
	if (print_state(data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	do_ordering(t_data *data)
{
	if (data->p.id % 2 == 0)
	{
		if (get_forks(data) == FAIL)
			return (FAIL);
	}
	pthread_mutex_unlock(&data->s->key.order);
	return (SUCCESS);
}

void	*routine_dining(void *data)
{
	if (do_ordering((t_data *)data) == FAIL)
		return ;
	while (((t_data *)data)->s->is_finished == FALSE)
	{
		if (get_forks_and_do_eating((t_data *)data) == FAIL
			|| do_sleeping_and_thinking((t_data *)data) == FAIL)
			break ;
	}
	//TODO: free data array, mutexes, 
	return ;
}
