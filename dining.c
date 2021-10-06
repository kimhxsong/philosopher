/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:27:35 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/10 13:41:45 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	routine_dining()
**	A Routine for the Dining Philosopher
*/

static int	getforks(t_args *args)
{
	t_shared	*s;
	t_private	*p;
	int			q;

	s = args->s;
	p = &args->p;
	if (pthread_mutex_lock(&s->fork[p->odd]) != 0)
	{	
		q = s->info.time_of_main / s->info.time_of_eating;
		p->time_of_thread += s->info.time_of_eating * q;
		p->state = STATE_ONE_FORK;
		if (print_state(args) == FAIL || pthread_mutex_lock(&s->fork[p->even]) != 0)
			return (FAIL);
		p->state = STATE_EATING;
		q = (s->info.time_of_main - p->end_of_sleeping) / s->info.time_of_eating;
		if (q < 0 || q > 1)
			return (FAIL);
		p->time_of_thread = p->end_of_eating + s->info.time_of_eating * q;
	}
	return (SUCCESS);
}

static int	do_eating(t_args *args)
{
	t_shared	*s;
	t_private	*p;

	s = args->s;
	p = &args->p;
	if (print_state(args) == SUCCESS)
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

static int do_sleeping(t_args *args)
{
	t_shared	*s;
	t_private	*p;

	s = args->s;
	p = &args->p;
	p->state = STATE_SLEEPING;
	p->time_of_thread = p->end_of_eating;
	if (print_state(args) == SUCCESS)
	{
		p->end_of_sleeping = p->time_of_thread + s->info.time_of_sleeping;
		while (s->info.time_of_main < p->end_of_sleeping)
		{
			if (usleep(2000) != 0)
				return (FAIL);
		}
		return (SUCCESS);
	}
	return (FAIL);
}

static int do_thinking(t_args *args)
{
	args->p.state = STATE_THINKING;
	args->p.time_of_thread = args->p.end_of_sleeping;
	return (print_state(args));
}

void	*routine_dining(void *data)
{
	int			i;
	t_args		*args;
	t_shared	*s;

	args = (t_args *)data;
	if (args != NULL && pthread_mutex_unlock(&args->s->key.order) == 0)
	{
		s = args->s;
		i = -1;
		while (++i < s->info.max_eat_number && s->info.someone_died == FALSE)
		{
			if (getforks(args) == FAIL \
				|| do_eating(args) == FAIL\
				|| do_sleeping(args) == FAIL\
				|| do_thinking(args) == FAIL)
				break ;
				// || putforks(args) == FAIL
		}
	}
	return (NULL);
}
