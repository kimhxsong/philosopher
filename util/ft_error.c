/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:16:24 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 06:45:51 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilx.h"

void	ft_error(const char *s, const char *strset[], int nerr)
{
	if (s)
		write(2, s, ft_strlen(s));
	write(2, ": ", 2);
	write(2, strset[nerr], ft_strlen(strset[nerr]));
}
