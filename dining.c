/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:27:35 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/10 17:56:20 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	routine_dining()
**	A Routine for the Dining Philosopher
*/

static int	get_forks(t_private *p, t_shared *s)
{
	int			q;

	if (p->state == STATE_THINKING)	
	{
		if (pthread_mutex_lock(&s->fork[p->odd]) != 0)
			return (FAIL);
		q = p->time_of_thread / s->info.time_of_eating;
		p->time_of_thread += s->info.time_of_eating * q;
		p->state = STATE_ONE_FORK;
	}
	if (p->state == STATE_ONE_FORK)
	{
		if (print_state(p, s) == FAIL || pthread_mutex_lock(&s->fork[p->even]) != 0)
			return (FAIL);
		p->state = STATE_EATING;
		q = (s->info.time_of_main - p->end_of_sleeping) / s->info.time_of_eating;
		if (q < 0 || q > 1)
			return (FAIL);
		p->time_of_thread = p->end_of_eating + s->info.time_of_eating * q;
	}
	return (SUCCESS);
}

static int	do_eating(t_private *p, t_shared *s)
{
	if (print_state(p, s) == SUCCESS)
	{
		p->time_to_die += s->info.time_to_die;
		p->end_of_eating = p->time_of_thread + s->info.time_of_eating;
		while(s->info.time_of_main < p->end_of_eating)
		{
			if (usleep(2000) != 0)
				return  (FAIL);
		}
		
		return (SUCCESS);
	}
	return (FAIL);
}

static int do_sleeping_and_thinking(t_private *p, t_shared *s)
{
	p->state = STATE_SLEEPING;
	p->time_of_thread = p->end_of_eating;
	if (print_state(p, s) == SUCCESS)
	{
		pthread_mutex_unlock(&s->fork[p->odd]);
		pthread_mutex_unlock(&s->fork[p->even]);
		p->end_of_sleeping = p->time_of_thread + s->info.time_of_sleeping;
		while (s->info.time_of_main < p->end_of_sleeping)
		{
			if (usleep(2000) != 0)
				return (FAIL);
		}
		return (SUCCESS);
	}
	p->state = STATE_THINKING;
	p->time_of_thread = p->end_of_sleeping;
	return (print_state(p, s));
	return (FAIL);
}

int		do_ordering(t_private *p, t_shared *s)
{
	if (p->id % 2 == 0)
	{
		if (pthread_mutex_lock(&s->fork[p->odd]) == 0)
			p->state = STATE_ONE_FORK;
		else
			return (FAIL);
	}
	if (pthread_mutex_unlock(&s->key.order) != 0)
		return (FAIL);
	return (SUCCESS);
}

void	*routine_dining(void *args)
{
	t_private	*p;
	t_shared	*s;
	int			i;

	p = &((t_args *)args)->p;
	s = ((t_args *)args)->s;
	if(do_ordering(p, s) == FAIL)
		return (NULL);
	i = -1;
	while (++i < s->info.max_eat_number && s->info.finish == FALSE)
	{
		if (get_forks(p, s) == FAIL)
			break ;
		if (do_eating(p, s) == FAIL)
			break ;
		if (do_sleeping_and_thinking(p, s) == FAIL)
			break ;
	}
	//TODO
	//destroy mutexs and free args
	return (NULL);
}
