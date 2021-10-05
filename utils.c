/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:56:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/05 21:11:15 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_strlen(const char *s)
{
	const char	*tmp;

	tmp = s;
	while (*s)
		s++;
	return (s - tmp);
}

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isdigits(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i != 0 && str[i] == '\0')
		return (1);
	return (0);
}

long long	ft_atoll(const char *str)
{
	unsigned long long	val;
	int					sign;

	val = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		sign = 44 - *str++;
	while (*str >= '0' && *str <= '9')
	{
		val *= 10;
		val += *str++ - '0';
	}
	if ((val >= 9223372036854775807LL) && sign == 1)
		return (-1);
	if ((val > 9223372036854775807LL) && sign == -1)
		return (0);
	return (sign * val);
}
