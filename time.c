/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:47:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/04 21:47:16 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*update_time(t_args *args)
{
	while (1)
	{
		gettimeofday(&(args->time->tp), NULL);
		args->shared->time_of_main = 1e+3 * args->time->tp.tv_sec + \
			1e-3 * args->time->tp.tv_usec - args->shared->time_of_main;
		if (usleep(200) == -1)
			break ;
	}
	return (NULL);
}
