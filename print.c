/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:21:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/10 17:52:04 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	select_message(char **msg, t_state state)
{
	const static char	*str[5] = {\
		"has taken a fork", \
		"is eating", \
		"is sleeping", \
		"is thinking", \
		"is died"};

	if (state < 0 || state >= 5)
		return (FAIL);
	*msg = (char *)str[state];
	return (SUCCESS);
}

int	print_state(t_private *p, t_shared *s)
{
	char		*msg;
	int			res;

	res = pthread_mutex_lock(&s->key.print) == 0 && \
		s->info.finish == FALSE && \
		select_message(&msg, p->state) == SUCCESS && \
		printf("%d\t%d\t%s\n", p->time_of_thread, p->id, msg) > 0 && \
		pthread_mutex_unlock(&s->key.print) == 0;
	if (p->state == STATE_DIED)
		s->info.finish = TRUE;
	return (ft_iternary(res, SUCCESS, FAIL));
}
