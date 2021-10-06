/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:17:19 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/10 13:40:44 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	routine_watch()
**	A routine for the thread \
**	that watches the philosopher's death in 1ms increments.
*/
void	*routine_watch(void	*data)
{
	t_args	*args;

	args = (t_args *)data;
	while (1)
	{
		if (args->s->info.time_of_main > args->p.time_to_die)
		{
			if (pthread_mutex_lock(&args->s->key.death) != 0)
				break ;
			args->p.time_of_thread = args->s->info.time_of_main;
			args->s->info.someone_died = TRUE;
			args->p.state = STATE_DIED;
			if (print_state(args) == -1 \
				|| pthread_mutex_unlock(&args->s->key.death) != 0 \
				|| usleep(1000) != 0)
				break ;
		}
	}
	return (NULL);
}