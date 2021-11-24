/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:33:43 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/24 11:21:53 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilx.h"

/*
 * ft_isintf(): 'is' it 'int' 'f'ormat?
 * ----------------------------------------------------------------------------
 * @param	(const char)str	: "[-,+][n zeros][int_min ~ int_max]"
 * @return	(int)			: if true, returns 1 else 0
 */
int	ft_isintf(const char *s)
{
	long long	num;

	if (!s)
		return (0);
	s += (ft_strchr("+-", *s) != NULL);
	if (*s == '\0')
		return (0);
	s += ft_strspn(s, "0");
	if (ft_strlen(s) > 10)
		return (0);
	num = ft_atoll(s);
	if ((num > 2147483647) || (num < -2147483648))
		return (0);
	s += ft_strspn(s, "0123456789");
	if (*s != '\0')
		return (0);
	return (1);
}
