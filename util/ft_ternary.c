/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:49:30 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/22 20:22:07 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilx.h"

int		ft_ternaryint(int d, int l, int r)
{
	if (!d)
		return (r);
	return (l);
}

void	*ft_ternaryptr(int d, void *l, void *r)
{
	if (!d)
		return (r);
	return (l);
}
