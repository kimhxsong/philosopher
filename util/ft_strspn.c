/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:17:10 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/22 20:22:24 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilx.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	const char	*p;

	p = s;
	while (*p)
	{
		if (!ft_strchr(charset, *p))
			break ;
		++p;
	}
	return (p - s);
}
