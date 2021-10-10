/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:17:19 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/10 17:53:34 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	routine_watch()
**	A routine for the thread \
**	that watches the philosopher's death in 1ms increments.
*/
void	*routine_watch(void	*args)
{
	t_private	*p;
	t_shared	*s;

	p = &((t_args *)args)->p;
	s = ((t_args *)args)->s;
	while (s->info.finish == 0 && usleep(200) == 0)
	{
		if (s->info.time_of_main > p->time_to_die)
		{
			p->time_of_thread = s->info.time_to_die;
			p->state = STATE_DIED;
			print_state(p, s);
		}
	}
	return (NULL);
}