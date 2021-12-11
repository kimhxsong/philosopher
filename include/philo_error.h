/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:20:38 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/11 15:57:32 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_ERROR_H
# define PHILO_ERROR_H

# include "philo.h"

const static char	*g_err[4] = {
	"too few arguments or too many arguments\n",
	"not in int format. \"[-,+][n zeros][int_min ~ int_max]\"\n",
	"argument value too small or negative\n",
	"too many philosophers\n"
};

void	init_error(int errnum);

#endif
