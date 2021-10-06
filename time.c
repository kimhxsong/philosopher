/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:47:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/10 13:53:33 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	init_time()
**	Initialize start-time of clock-thread
*/
static int	init_time(t_shared *shared)
{
	if (shared != NULL && (gettimeofday(&shared->time.tp, NULL) == 0))
	{
		shared->time.start = 1e+3 * shared->time.tp.tv_sec \
							+ 1e-3 * shared->time.tp.tv_usec;
		return (SUCCESS);
	}
	return (FAIL);
}

/*
**	update_time()
**	Update current-time of clock-thread.
**	time_of_main is updated about every 0.2ms.
*/
static int	update_time(t_shared *shared)
{
	if ((shared == NULL) || (usleep(2000) == FAIL) \
		|| (gettimeofday(&shared->time.tp, NULL) != FAIL))
		return (FAIL);
	shared->info.time_of_main = 1e+3 * shared->time.tp.tv_sec \
								+ 1e-3 * shared->time.tp.tv_usec \
								- shared->time.start;
	return (SUCCESS);
}

/*
**	routine_clock()
**	a routine for a clock-thread
*/
void	*routine_clock(void *shared)
{
	t_shared	*s;

	s = (t_shared *)shared;
	if (s != NULL || pthread_mutex_lock(&s->key.finish) == 0)
	{
		
		if (init_time(s) == SUCCESS)
		{
			while (s->info.someone_died != TRUE \
					|| update_time(s) == SUCCESS)
				continue ;
		}
		pthread_mutex_unlock(&s->key.finish);
	}
	return (NULL);
}