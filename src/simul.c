/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:15:37 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/11 15:53:44 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	simul_start_threads(t_data *data)
{
	pthread_t		task;
	int				num_of_philos;
	int				i;
	
	num_of_philos = data->s->info[0];
	i = -1;
	while (++i < num_of_philos)
	{
		if (pthread_mutex_lock(&data->s->key.order)
			|| pthread_create(&task, 0, routine_dining, (void *)&data[i])
			|| pthread_detach(task)
			|| pthread_create(&task, 0, routine_detect, (void *)&data[i])
			|| pthread_detach(task))
			return (-1);
	}
	return (0);
}

static void	simul_start_clock(t_data *data)
{
	t_clock	*clock;

	clock = &data->s->clock;
	gettimeofday(&clock->tp, NULL);
	clock->start = 1e+3 * clock->tp.tv_sec + 1e-3 * clock->tp.tv_usec;
	while (data->s->alive > 0)
	{
		clock->current = 1e+3 * clock->tp.tv_sec + 1e-3
			* clock->tp.tv_usec - clock->start;
		usleep(2000);
		gettimeofday(&clock->tp, NULL);
	}
}

static void	simul_cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (++i < data->s->info[0])
			pthread_mutex_destroy(&data->s->forks[i]);
	free(data->s->forks);
	pthread_mutex_destroy(&data->s->key.order);
	pthread_mutex_destroy(&data->s->key.death);
	pthread_mutex_destroy(&data->s->key.print);
	free(data);
}

int	simul(t_data *data)
{
	if (!data || simul_start_threads(data))
		return (EXIT_FAILURE);
	simul_start_clock(data);
	simul_cleanup(data);
	return (EXIT_SUCCESS);
}