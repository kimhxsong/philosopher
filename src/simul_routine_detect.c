/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_routine_detect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:17:19 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/27 01:34:45 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_detect(void *data)
{
	t_shared	*s;
	t_private	*p;

	s = ((t_data *)data)->s;
	p = &((t_data *)data)->p;
	while (s->is_finished == FALSE)
	{
		usleep(500);
		if (s->clock.current > p->time_to_die)
		{
			pthread_mutex_lock(&s->key.death);
			pthread_mutex_lock(&s->key.print);
			p->time_of_thread = p->time_to_die;
			p->state = STATE_DIED;
			if (s->is_finished == FALSE)
				printf("%d\t%d\t%s\n", p->time_of_thread, p->id, (char *)g_msg[STATE_DIED]);
			s->is_finished = TRUE;
			pthread_mutex_unlock(&s->key.print);
			pthread_mutex_unlock(&s->key.death);
			break ;
		}
	}
	pthread_mutex_unlock(&s->fork[p->second]);
	pthread_mutex_unlock(&s->fork[p->first]);
	return (NULL);
}
