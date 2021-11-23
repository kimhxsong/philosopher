/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:27:35 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 09:28:38 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	routine_dining()
**	A Routine for the Dining Philosopher
*/
static int	get_forks(t_private *p, t_shared *s)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;
	int				q;
	
	first = &s->fork[p->first];
	second = &s->fork[p->second];
	if (p->state == STATE_THINKING)	
	{
		pthread_mutex_lock(first);
		// printf("THREAD[%d] TAKEN FORK[%d]\n", p->id, p->first);
		q = (s->time.current - p->time_of_thread) / s->info.time_of_eating;
		p->time_of_thread += q * s->info.time_of_eating;
		p->state = STATE_ONE_FORK;
	}
	else if (p->state == STATE_ONE_FORK && print_state(p, s) == 0)
	{
		pthread_mutex_lock(second);
		// printf("THREAD[%d] EATING[%d]\n", p->id, p->second);
		q = (s->time.current - p->time_of_thread) / s->info.time_of_eating;
		p->time_of_thread += q * s->info.time_of_eating;
		p->state = STATE_EATING;
	}
	else
		return (-1);
	return (0);
}

static int	do_eating(t_private *p, t_shared *s)
{
	if (p->state == STATE_EATING && print_state(p, s) == 0)
	{	
		p->time_to_die = p->time_of_thread + s->info.time_to_die;
		p->end_of_eating = p->time_of_thread + s->info.time_of_eating;
		p->num_of_eat += 1;
		while(s->time.current < p->end_of_eating)
			usleep(200);
		p->time_of_thread = p->end_of_eating;
		p->state = STATE_SLEEPING;
	}
	else
		return (-1);
	return (0);
}

static int do_sleeping_and_thinking(t_private *p, t_shared *s)
{
	if (p->state == STATE_SLEEPING && print_state(p, s) == 0)
	{
		if (p->num_of_eat > (int)s->info.max_eat_number)
			p->state = STATE_FULL;
		pthread_mutex_unlock(&s->fork[p->second]);
		pthread_mutex_unlock(&s->fork[p->first]);
		p->end_of_sleeping = p->time_of_thread + s->info.time_of_sleeping;
		while (s->time.current < p->end_of_sleeping)
			usleep(200);
		p->time_of_thread = p->end_of_sleeping;
		p->state = STATE_THINKING;
	}
	else
		return (-1);
	if (p->state == STATE_THINKING && print_state(p, s) == -1)
		return (-1);
	return (0);
}

static int	do_ordering(t_private *p, t_shared *s)
{
	int	res;

	res = 0;
	// printf("THREAD[%d] KEY LOCKED F[%d], S[%d]\n", p->id, p->first, p->second);
	if (p->id % 2 == 0)
		res = get_forks(p, s) || get_forks(p, s);
	pthread_mutex_unlock(&s->key.order);
	// printf("THREAD[%d] KEY ONLOCKED F[%d], S[%d]\n", p->id, p->first, p->second);
	return (res);
}

void	*routine_dining(void *args)
{
	t_private	*p;
	t_shared	*s;

	p = &((t_args *)args)->p;
	s = ((t_args *)args)->s;
	// printf("[%d] routine start\n", p->id);
	if(do_ordering(p, s) != 0)
	{
		s->finish = 1;
		pthread_mutex_unlock(&s->key.order);
		return (NULL);
	}
	// printf("[%d] after ordering \n", p->id);
	while (s->finish == 0)
	{
		get_forks(p, s);
		do_eating(p, s);
		do_sleeping_and_thinking(p, s);
	}
	printf("[%d] loop out\n", p->id);
	return (NULL);
}
