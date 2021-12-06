/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:50:43 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/01 19:50:21 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_shared_info(int *info, int argc, char **argv)
{
	int	i;

	info[4] = INT_MAX;
	i = 0;
	while (++i < argc)
	{
		info[i - 1] = ft_atoi(argv[i]);
		if (!ft_ispositive(info[i - 1]))
			return (-1);
	}
	return (0);
}

static int	init_shared_mutexes(t_shared *shared)
{
	int	num_of_philos;
	int	i;
	
	num_of_philos = shared->info[0];
	shared->alive = num_of_philos;
	i = -1;
	shared->forks = (pthread_mutex_t *)safe_malloc(num_of_philos
		* sizeof(pthread_mutex_t));
	while (++i < num_of_philos)
	{
		if (pthread_mutex_init(&shared->forks[i], NULL) < 0)
			return (-1);
	}
	if (pthread_mutex_init(&shared->key.order, NULL)
		|| pthread_mutex_init(&shared->key.death, NULL)
		|| pthread_mutex_init(&shared->key.print, NULL))
		return (-1);
	return (0);
}

static void init_data_and_private(t_data *data, t_shared *shared)
{
	int		num_of_philos;
	int 	i;

	num_of_philos = shared->info[0];
	i = -1;
	while (++i < num_of_philos)
	{
		data[i].s = shared;
		data[i].p.id = i + 1;
		data[i].p.time_to_die = shared->info[1];
		data[i].p.first = &shared->forks[i];
		data[i].p.second = &shared->forks[(i + 1) % num_of_philos];
		data[i].p.state = STATE_THINKING;
	}
}

t_data *init(t_shared *shared, int argc, char **argv)
{
	t_data	*data;

	if (validate_argc(argc) || validate_argv(argc, argv))
		return (NULL);
	if (init_shared_info((int *)shared->info, argc, argv))
		return (NULL);
	if (init_shared_mutexes(shared))
		return (NULL);
	data = (t_data *)safe_malloc(shared->info[0] * sizeof(t_data));
	init_data_and_private(data, shared);
	return (data);
}
