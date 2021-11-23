/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:17:19 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 06:37:41 by hyeonsok         ###   ########.fr       */
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
		usleep(500);
		if (s->time.current > p->time_to_die)
		{
			pthread_mutex_lock(&s->key.death);
			pthread_mutex_lock(&s->key.print);
			p->time_of_thread = p->time_to_die;
			p->state = STATE_DIED;
			if (s->finish == 0)
				printf("%d\t%d\t%s\n", p->time_of_thread, p->id, (char *)g_msg[STATE_DIED]);
			s->finish = 1;
			pthread_mutex_unlock(&s->key.print);
			pthread_mutex_unlock(&s->key.death);
			break ;
		}
	}
	pthread_mutex_unlock(&s->fork[p->second]);
	pthread_mutex_unlock(&s->fork[p->first]);
	printf("WATCH[%d] OUT\n", p->id);
	return (NULL);
}