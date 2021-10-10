/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:35:10 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/10 17:21:24 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(t_args **args, t_shared *shared)
{
	int		i;
	
	if (args == NULL || shared == NULL)
		return (FAIL);
	*args = (t_args *)malloc(sizeof(t_args) * shared->info.number_of_philo);
	shared->fork = (pthread_mutex_t *)malloc(sizeof(t_args) \
					* (shared->info.number_of_philo + 1));
	if (*args == NULL || shared->fork == NULL)
		return (FAIL);
	shared->fork[shared->info.number_of_philo] = shared->fork[0];
	i = -1;
	while (++i < shared->info.number_of_philo)
	{
		pthread_mutex_init(&shared->fork[i], NULL);
		(*args)[i].s = shared;
		(*args)[i].p.id = i;
		(*args)[i].p.even = i + i % 2;
		if (i % 2 == 0)
			(*args)[i].p.odd = i + i % 2 + 1;
		else
			(*args)[i].p.odd = i + i % 2 - 1;
		(*args)[i].p.time_of_thread = 0;
		(*args)[i].p.time_to_die = shared->info.time_to_die;
		(*args)[i].p.state = STATE_THINKING;
		(*args)[i].p.end_of_eating = shared->info.time_of_eating;
		(*args)[i].p.end_of_sleeping = 0;
	}
	pthread_mutex_init(&shared->key.death, NULL);
	pthread_mutex_init(&shared->key.order, NULL);
	pthread_mutex_init(&shared->key.print, NULL);
	return (SUCCESS);
}

int	simul(t_shared *shared)
{
	t_args		*args;
	pthread_t	task;
	int			i;
	int			res;

	if (args == NULL || init_args(&args, shared) == FAIL)
		return (FAIL);
	i = -1;
	while (++i < shared->info.number_of_philo)
	{
		res = pthread_mutex_lock(&args->s->key.order);
		printf("loop[%d] %d\n", i, res);
		if (pthread_create(&task, NULL, routine_dining, (void *)&args[i]) != 0 \
			|| pthread_detach(task) != 0)
			return (FAIL);
		if (pthread_create(&task, NULL, routine_watch, (void *)&args[i]) != 0 \
			|| pthread_detach(task) != 0)
			return (FAIL);
	}
	if (shared->info.number_of_philo % 2 == 1)
		pthread_mutex_unlock(&shared->key.order);
	if (init_time(shared) == FAIL)
		return (FAIL);
	while (shared->info.finish == 0)
	{
		if(usleep(2000) != 0 || gettimeofday(&shared->time.tp, NULL) != 0)
			return (FAIL);
		shared->info.time_of_main = 1e+3 * shared->time.tp.tv_sec \
								+ 1e-3 * shared->time.tp.tv_usec \
								- shared->time.start;
	}
	return (SUCCESS);
}

int	main(int ac, char *av[])
{
	t_shared	shared;

	if (parse(&shared, ac, av) == FAIL)
		return (1);
	if (simul(&shared) == FAIL)
		return (2);
	return (0);
}
