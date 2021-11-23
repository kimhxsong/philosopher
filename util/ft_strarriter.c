/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarriter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:25:02 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 09:23:43 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilx.h"

/*
 * ft_iterargv(): iterate over argument vetors as argument to is_functions()
 * ----------------------------------------------------------------------------
 * @param	(size_t)size			: sizeof(strarr)
 * @param	(const char *)strarr[]	: string array
 * @param	int f(const char *))
 * @return	int						: if success then returns 0 else returns -1
 */
int	ft_strarriter(size_t size, char *strarr[], int isfp(const char *))
{
	size_t	i;
	
	i = 0;
	while (++i < size)
	{
		if (!isfp(strarr[i]))
			return (-1);
	}
	return (0);
}
