/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:47:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/24 18:19:04 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * init_clcok(): Initialize start-time of clock-thread.
 * ----------------------------------------------------------------------------
 */
int	init_clock(t_clock *clock)
{
	if (gettimeofday(&clock->tp, NULL) != SUCCESS)
		return (FAIL);
	clock->start = 1e+3 * clock->tp.tv_sec + 1e-3 * clock->tp.tv_usec;
	return (SUCCESS);
}

/**
 * update_clcok(): Update current-time of clock-thread.
 * ----------------------------------------------------------------------------
*/
void	update_clock(t_clock *clock)
{
	clock->current = 1e+3 * clock->tp.tv_sec + 1e-3 * clock->tp.tv_usec
		- clock->start;
	return ;
}
