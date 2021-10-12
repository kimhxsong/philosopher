/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:21:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/12 18:13:18 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_state(t_private *p, t_shared *s)
{
	pthread_mutex_lock(&s->key.print);
	if (s->finish == TRUE)
		return (FAIL);
	if (p->state == STATE_FULL)
		s->finish = TRUE;
	if (p->state < 0 || p->state > 4)
	{ 
		pthread_mutex_unlock(&s->key.print);
		return (FAIL);
	}
	printf("%d\t%d\t%s\n", p->time_of_thread, p->id, (char *)g_msg[p->state]);
	// if (p->state == STATE_ONE_FORK)
	// 	printf("[%d]\t%.f\n", p->first % s->info.number_of_philo, s->time.current);
	// else if (p->state == STATE_EATING)
	// 	printf("[%d]\t%.f\n", p->second, s->time.current);
	// else
	// 	printf("\n");
	pthread_mutex_unlock(&s->key.print);
	return (SUCCESS);
}
