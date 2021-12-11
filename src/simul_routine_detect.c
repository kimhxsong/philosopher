/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_routine_detect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:17:19 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/11 16:46:08 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_detect(void *data)
{
	t_shared	*s;
	t_private	*p;

	s = ((t_data *)data)->s;
	p = &((t_data *)data)->p;
	while (s->hungry > 0)
	{
		usleep(2000);
		if (s->clock.current >= p->time_to_die)
		{
			p->time_of_thread = s->clock.current;
			p->state = STATE_DIED;
			print_state((t_data *)data);
			break ;
		}
	}
	pthread_mutex_unlock(p->second);
	pthread_mutex_unlock(p->first);
	return (NULL);
}
