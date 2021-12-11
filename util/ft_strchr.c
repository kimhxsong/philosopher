/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:18:39 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/11 16:36:08 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*ft_strchr(const char *s, int c)
{
	const char	ch = c;

	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		++s;
	}
	return (NULL);
}
