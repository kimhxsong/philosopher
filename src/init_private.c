/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_private.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:23:26 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/24 15:54:19 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	malloc_to_data(t_data **data, t_shared *shared)
{
	*data = (t_data *)malloc(shared->info.number_of_philo * sizeof(t_data));
	shared->fork = (pthread_mutex_t *)malloc((shared->info.number_of_philo)
											* sizeof(pthread_mutex_t));
	return (*data == NULL || shared->fork == NULL);
}

static void	fill_private(t_data **data, t_shared *shared)
{	
	const int	num_of_philos = shared->info.number_of_philo;
	int 		i;

	i = -1;
	while (++i < num_of_philos)
	{
		ft_memset((void *)data[i], 0, sizeof(t_data));
		data[i]->s = shared;
		data[i]->p.id = i + 1;
		data[i]->p.time_to_die = shared->info.time_to_die;
		data[i]->p.first = i;
		data[i]->p.second = (i + 1) % shared->info.number_of_philo;
		if (num_of_philos % 2 == 0 && data[i]->p.id % 2 == 0)
		{
			data[i]->p.first = (i + 1) % num_of_philos;
			data[i]->p.second = i;
		}
		data[i]->p.state = STATE_THINKING;
	}
}

int	init_private(t_data **data, t_shared *shared)
{
	if (malloc_to_data(data, shared) == FAIL)
		return (FAIL);
	fill_private(data, shared);
	return (SUCCESS);
}