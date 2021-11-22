/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarriter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:25:02 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/22 20:22:34 by hyeonsok         ###   ########.fr       */
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
int	ft_strarriter(size_t size, const char *strarr[], int f(const char *))
{
	while (size-- > 0)
	{
		if (!isfp(*strarr))
			return (-1);
		*strarr += 1;
	}
	return (0);
}
