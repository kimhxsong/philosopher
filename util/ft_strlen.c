/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:35:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 04:34:45 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilx.h"

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		++p;
	return (p - s);
}
