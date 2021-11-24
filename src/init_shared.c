/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shared.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:05:13 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/24 17:34:40 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	validate_info(t_info *info)
{
	return ((info->is_max_used
		&& is_positive(info->max_eat_number) == FALSE)
		|| is_positive(info->number_of_philo) == FALSE
		|| is_positive(info->time_to_die) == FALSE
		|| is_positive(info->time_of_eating == FALSE)
		|| is_positive(info->time_of_sleeping) == FALSE);
}

static int	init_info(t_info *info, int ac, char *av[])
{
	info->number_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_of_sleeping = ft_atoi(av[3]);
	info->time_of_eating = ft_atoi(av[4]);
	if (ac == 6)
	{
		info->is_max_used = 1;
		info->max_eat_number = ft_atoi(av[5]);
	}
	return (validate_info(info) == FAIL);
}

static int	init_mutexes(t_shared *shared)
{
	const int	num_of_philos = shared->info.number_of_philo;
	int			i;
	
	i = -1;
	while (++i < num_of_philos)
	{
		if (pthread_mutex_init(&shared->fork[i], NULL) != SUCCESS)
			return (FAIL);
	}
	return (pthread_mutex_init(&shared->key.death, NULL) != SUCCESS
		|| pthread_mutex_init(&shared->key.order, NULL) != SUCCESS
		|| pthread_mutex_init(&shared->key.print, NULL) != SUCCESS);
}

int	init_shared(t_shared *shared, int argc, char **argv)
{
	ft_memset((void *)shared, 0, sizeof(t_shared));
	return (init_info(&shared->info, argc, argv) == FAIL
		|| init_mutexes(shared) == FAIL);
}
