/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simul.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:17:25 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 06:12:27 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_SIMUL_H
# define PHILO_SIMUL_H

#include "philo.h"

const static char	*g_msg[5] = \
{
	"\033[1;33m has taken a fork\033[0;0m", \
	"\033[0;32m is eating\033[0;0m", \
	"\033[0;35m is sleeping\033[0;0m", \
	"\033[0;36m is thinking\033[0;0m", \
	"\033[0;31m died\033[0;0m"\
};

int			print_state(t_private *p, t_shared *s);
int			simulate(t_shared *s);

/*
**	routines in time.c, dining.c and watch.c
*/
void		*routine_clock(void *shared);
void		*routine_dining(void *args);
void		*routine_watch(void *args);

#endif
