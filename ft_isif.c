/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isif.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:33:43 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/05 20:52:54 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** ft_isif() means " 'is' it 'i'nt 'f'ormat?"
** arument: str = "[-,+][n zeros][int_min ~ int_max]"
** return: if true, returns 1 else 0
*/
int	ft_isif(char *str)
{
	unsigned long long	num;
	int					i;

	if (str != NULL)
	{
		i = ft_issign(str[0]);
		if (ft_isdigits(str[i]) == 1)
		{
			while (str[i] == '0')
				i++;
			if (ft_strlen(&str[i]) <= 10)
			{
				num = ft_atoll(str);
				if (num <= 2147483647 || num >= -2147483648)
					return (1);
			}
		}
	}
	return (0);
}
