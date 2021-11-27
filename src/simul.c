/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:15:37 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/27 01:41:26 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	simul_start_threads(t_data *data)
{
	pthread_t	task;
	int			num_of_philos;
	int			i;
	
	num_of_philos = data->s->info.number_of_philo;
	i = -1;
	while (++i < num_of_philos)
	{
		if (pthread_mutex_lock(&data->s->key.order)
			|| pthread_create(&task, 0, routine_dining, (void *)&data)
			|| pthread_detach(task)
			|| pthread_create(&task, 0, routine_detect, (void *)&data)
			|| pthread_detach(task))
			return (FAIL);
		++data;
	}
	return (SUCCESS);
}

static int	simul_start_clock(t_shared *shared)
{
	if (init_clock(&shared->clock) == FAIL)
		return (FAIL);
	while (shared->is_finished == FALSE)
	{
		shared->clock.current = 1e+3 * shared->clock.tp.tv_sec
			+ 1e-3 * shared->clock.tp.tv_usec - shared->clock.start;
		usleep(500);
		gettimeofday(&shared->clock.tp, NULL);
	}
	return (SUCCESS);
}

int	simul(t_data *data)
{
	if (!data)
	{
		//TODO: Add error handling
		return (FAIL);
	}
	return (simul_start_threads(data) == FAIL
		|| simul_start_clock(data->s) == FAIL);
}
