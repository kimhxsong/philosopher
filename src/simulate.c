/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:15:37 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/22 21:15:54 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_private(t_args *args, t_shared *s, int i)
{
	int	first;
	int	second;
	
	first = 0;
	second = 0;
	memset((void *)args, 0, sizeof(args));
	args->s = s;
	args->p.id = i;
	args->p.time_to_die = s->info.time_to_die;
	args->p.first = i;
	args->p.second = (i + 1) % s->info.number_of_philo;
	if (s->info.number_of_philo % 2 == 0 && args->p.id % 2 == 0)
	{
		args->p.first = (i + 1) % s->info.number_of_philo;
		args->p.second = i;
	}
	args->p.state = STATE_THINKING;
	// args->p.second = (i + i % 2) % s->info.number_of_philo;
	// if (i % 2 == 0)
	// 	args->p.first = (i + i % 2 + 1) % s->info.number_of_philo;
	// else
	// 	args->p.first = i + i % 2 - 1;
	// args->p.time_of_thread = 0;
	// args->p.end_of_eating = 0;
	// args->p.end_of_sleeping = 0;
	// args->p.num_of_eat = 0;
}

static int	init_args(t_args **args, t_shared *s)
{
	int		res;
	int		i;

	*args = (t_args *)malloc(sizeof(t_args) * s->info.number_of_philo);
	s->fork = (pthread_mutex_t *) \
			   malloc(sizeof(pthread_mutex_t) * (s->info.number_of_philo + 1));
	if (*args == NULL || s->fork == NULL)
		return (FAIL);
	s->fork[s->info.number_of_philo] = s->fork[0];
	i = s->info.number_of_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&s->fork[i], NULL) == 0)
			init_private(&((*args)[i]), s, i);
		else
			break ;
	}
	res = ++i || pthread_mutex_init(&s->key.death, NULL) \
			  || pthread_mutex_init(&s->key.order, NULL) \
			  || pthread_mutex_init(&s->key.print, NULL);
	return (res);
}

int	simul(t_shared *s)
{
	t_args		*args;
	pthread_t	task;
	int			i;
	int			res;

	res = (s == NULL) || (init_args(&args, s) != 0);
	i = -1;
	while (res == 0 && ++i < s->info.number_of_philo)
	{
		res = pthread_mutex_lock(&args->s->key.order) \
		   || pthread_create(&task, NULL, routine_dining, (void *)&args[i]) \
		   || pthread_detach(task) \
		   || pthread_create(&task, NULL, routine_watch, (void *)&args[i]) \
		   || pthread_detach(task);
	}
	res = (init_time(s) == FAIL);
	while (res == 0 && s->finish == FALSE)
	{
		s->time.current = 1e+3 * s->time.tp.tv_sec \
							 + 1e-3 * s->time.tp.tv_usec - s->time.start;
		res = usleep(500) || gettimeofday(&s->time.tp, NULL);
	}
	if (res == 0)
		return (SUCCESS);
	return (FAIL);
}
