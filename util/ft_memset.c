/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 06:33:12 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 06:35:20 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len > 0)
	{
		*p++ = (unsigned char)c;
		--len;
	}
	return (b);
}