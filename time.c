/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:47:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/05 17:28:10 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_time(t_args *args);
static int	update_time(t_args *args);

/*
**	clock()
**	a routine for a clock-thread
*/
void	*clock(t_args *args)
{
	if (init_time(args) == success)
	{
		while (args->shared->someone_died != true \
				|| update_time(args) == success)
			continue ;
	}
	return (NULL);
}

/*
**	init_time()
**	Initialize start-time of clock-thread
*/
static int	init_time(t_args *args)
{
	if (gettimeofday(&(args->time->tp), NULL) == success)
	{
		args->time->start = 1e+3 * args->time->tp.tv_sec + \
							1e-3 * args->time->tp.tv_usec;
		return (success);
	}
	return (fail);
}

/*
**	update_time()
**	Update current-time of clock-thread.
**	time_of_main is updated about every 0.2ms.
*/
static int	update_time(t_args *args)
{
	if (usleep(200) != success \
		|| gettimeofday(&(args->time->tp), NULL) != success)
		return (fail);
	args->shared->time_of_main = 1e+3 * args->time->tp.tv_sec + \
						1e-3 * args->time->tp.tv_usec - args->time->start;
	return (success);
}
