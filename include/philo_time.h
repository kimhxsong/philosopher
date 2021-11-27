/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:17:27 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/27 01:39:59 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_TIME_H
# define PHILO_TIME_H

# include "philo.h"

int		init_clock(t_clock *clock);
void	update_clock(t_clock *clock);

#endif
