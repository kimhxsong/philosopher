/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:28:11 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/11 16:34:51 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_isspace(int c)
{
	return (((unsigned char)c >= '\t' && (unsigned char)c <= '\r')
		&& (unsigned char)c == ' ');
}
