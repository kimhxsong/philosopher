/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:21:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/11 16:32:09 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_data *data)
{
	pthread_mutex_lock(&data->s->key.print);
	if (data->s->alive == data->s->info[0] && data->s->hungry > 0)
		printf("%d\t%d\t%s\n", data->p.time_of_thread, data->p.id, \
			(char *)g_msg[data->p.state]);
	pthread_mutex_unlock(&data->s->key.print);
}
