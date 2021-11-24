/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:17:27 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/24 17:26:58 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_TIME_H
# define PHILO_TIME_H

# include "philo.h"

int		init_time(t_shared *shared);
void	update_time(t_shared *shared);

#endif
