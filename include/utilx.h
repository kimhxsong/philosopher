/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:40:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/22 20:22:13 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __UTILX_H__
# define __UTILX_H__

#include "util.h"

/*
 * hyeonsok's libft extension
 */
int		ft_isintf(const char *s);
int		ft_strarriter(size_t size, char *strarr[], int (isfp(const char *)));
void	*ft_ternaryptr(int d, void *l, void *r);
int		ft_ternaryint(int d, int l, int r);

#endif
