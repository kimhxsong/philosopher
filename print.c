/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:21:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/09 21:44:26 by hyeonsok         ###   ########.fr       */
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

int	print_state(t_args *args)
{
	t_private	*p;
	t_state		state;
	char		*msg;
	int			res;

	p = &args->p;
	state = args->p.state;
	res = args->p.state != STATE_DIED && \
		pthread_mutex_lock(&args->s->key.print) == 0 && \
		args->s->info.someone_died == FALSE && \
		select_message(&msg, state) == SUCCESS && \
		printf("%d\t%d\t%s\n", p->time_of_thread, p->id, msg) > 0 && \
		pthread_mutex_unlock(&args->s->key.print) == 0;
	return (ft_iternary(res, SUCCESS, FAIL));
}
