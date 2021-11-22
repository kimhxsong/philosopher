/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:20:38 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/22 21:50:48 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_ERROR_H
# define PHILO_ERROR_H

#include "philo.h"

//const static char *g_err[3] = \
//{
//	"parse: too few arguments or too many arguments\n", \
//	"parse: not in int format. \"[-,+][n zeros][int_min ~ int_max]\"\n", \
//	"parse: argument value too small or negative"\
//};

void	ft_perror(const char *s, const char *strset[], int i);

#endif
