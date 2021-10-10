/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:17:19 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/12 14:27:00 by hyeonsok         ###   ########.fr       */
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
	while (s->finish == 0)
	{
		usleep(200);
		if (s->time.current > p->time_to_die)
		{
			pthread_mutex_lock(&s->key.death);
			p->time_of_thread = p->time_to_die;
			p->state = STATE_DIED;
			if (print_state(p, s) == SUCCESS)
				printf("WATCH[%d]\tmain:%f\ttime_to_die:%u\n", p->id, s->time.current, p->time_to_die);
			pthread_mutex_unlock(&s->key.death);
			break ;
		}
	}
	return (NULL);
}