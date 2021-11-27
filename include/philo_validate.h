/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_validate.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:43:51 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/30 16:35:06 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_TIME_H
# define PHILO_TIME_H

#include "philo.h"

void	*safe_malloc(size_t len);
int		validate_argv(int argc, char *argv[]);
int		validate_argc(int argc);


# endif