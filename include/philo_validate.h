/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_validate.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:43:51 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/11 16:28:12 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_VALIDATE_H
# define PHILO_VALIDATE_H

# include "philo.h"

void	*custom_malloc(size_t len);
int		validate_argv(int argc, char *argv[]);
int		validate_argc(int argc);

#endif
