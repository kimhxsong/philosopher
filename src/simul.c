/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:15:37 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/30 19:42:32 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	simul_start_threads(t_data *data)
{
	pthread_t		task;
	pthread_mutex_t	*order;
	int				num_of_philos;
	int				i;
	
	order = &data->s->key.order;
	num_of_philos = data->s->info[0];
	i = -1;
	while (++i < num_of_philos)
	{
		if (pthread_mutex_lock(order)
			|| pthread_create(&task, 0, routine_dining, (void *)&data[i])
			|| pthread_detach(task)
			|| pthread_create(&task, 0, routine_detect, (void *)&data[i])
			|| pthread_detach(task))
			return (-1);
	}
	return (0);
}

static void	simul_start_clock(t_shared *shared)
{
	t_clock	*clock;

	clock = &shared->clock;
	gettimeofday(&clock->tp, NULL);
	clock->start = 1e+3 * clock->tp.tv_sec + 1e-3 * clock->tp.tv_usec;
	while (!shared->is_finished)
	{
		clock->current = 1e+3 * clock->tp.tv_sec + 1e-3
			* clock->tp.tv_usec - clock->start;
		usleep(500);
		gettimeofday(&clock->tp, NULL);
	}
}

int	simul(t_data *data)
{
	if (!data || simul_start_threads(data))
		return (EXIT_FAILURE);
	simul_start_clock(data->s);
	return (EXIT_SUCCESS);
}