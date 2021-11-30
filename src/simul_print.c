/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:21:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/30 19:28:47 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_state(t_data *data)
{
	pthread_mutex_lock(&data->s->key.print);
	if (data->s->is_finished == TRUE)
		return (-1);
	if (data->p.state == STATE_FULL)
		data->s->is_finished = TRUE;
	printf("%d\t%d\t%s\n", data->p.time_of_thread, data->p.id
		, (char *)g_msg[data->p.state]);
	pthread_mutex_unlock(&data->s->key.print);
	return (0);
}
