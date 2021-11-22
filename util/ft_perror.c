/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:32:28 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/22 21:50:51 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_error.h"

void	ft_perror(const char *s, const char *strset[], int i)
{
	write(2, s, ft_strlen(s));
	write(2, ": ", 2);
	write(2, strset[i], ft_strlen(strset[i]));
}