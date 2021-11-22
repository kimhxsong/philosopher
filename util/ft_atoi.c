/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 05:25:00 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 05:32:46 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_atoi(const char *s)
{
	unsigned int	val;
	int				sym;

	val = 0;
	sym = 1;
	while (ft_isspace(*s) != 0)
		s++;
	if (ft_strchr("+-", *s))
		sym = 44 - *s++;
	while (ft_isdigit(*s))
	{
		val *= 10;
		val += *s++ - '0';
	}
	return (sym * val);
}
