/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:56:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 05:26:13 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

long long	ft_atoll(const char *s)
{
	unsigned long long	val;
	int					sym;

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
	if ((val >= 9223372036854775807LL) && sym == 1)
		return (-1);
	if ((val > 9223372036854775807LL) && sym == -1)
		return (0);
	return (sym * val);
}
