/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:50:43 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/11 15:56:46 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_shared_info(int *info, int argc, char **argv)
{
	int	i;

	if (argc == 5)
		info[4] = -1;
	i = 0;
	while (++i < argc)
	{
		info[i - 1] = ft_atoi(argv[i]);
		if (!ft_ispositive(info[i - 1]))
		{
			ft_error("init_shared_info", g_err, 2);
			return (-1);
		}
	}
	if (info[0] > PTHREAD_STACK_MIN / 2)
	{
		ft_error("init_shared_info", g_err, 3);
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
	shared->hungry = num_of_philos;
	i = -1;
	shared->forks = (pthread_mutex_t *)custom_malloc(num_of_philos
		* sizeof(pthread_mutex_t));
	if (!shared->forks)
		return (-1);
	while (++i < num_of_philos)
		if (pthread_mutex_init(&shared->forks[i], NULL) < 0)
			return (-1);
	if (pthread_mutex_init(&shared->key.order, NULL) < 0
		|| pthread_mutex_init(&shared->key.death, NULL) < 0
		|| pthread_mutex_init(&shared->key.print, NULL) < 0)
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

static void	init_cleanup(t_data *data, t_shared *shared)
{
	int	i;

	i = 0;
	if (shared->forks != NULL)
	{
		while (++i < shared->info[0])
			pthread_mutex_destroy(&shared->forks[i]);
		free(shared->forks);
	}
	pthread_mutex_destroy(&shared->key.order);
	pthread_mutex_destroy(&shared->key.death);
	pthread_mutex_destroy(&shared->key.print);
	free(data);
}

t_data *init(t_shared *shared, int argc, char **argv)
{
	t_data	*data;

	if (validate_argc(argc) || validate_argv(argc, argv))
		return (NULL);
	if (init_shared_info((int *)shared->info, argc, argv))
		return (NULL);
	data = (t_data *)custom_malloc(shared->info[0] * sizeof(t_data));
	if (!data || init_shared_mutexes(shared))
	{
		init_cleanup(data, shared);
		return (NULL);
	}
	init_data_and_private(data, shared);
	return (data);
}
