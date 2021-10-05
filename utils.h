/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:34:23 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/06 02:46:40 by hyeonsok         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

/*
** ft_%.c
*/
int				ft_isif(char *str);
int				ft_iterargv(int ac, char *av[], int (*isfptr(char *)));
void			ft_iternary(int d, int a, int b);
void			*ft_pternary(int d, void *a, void *b);

/*
** utils.c
** Functions used in previous projects
*/
unsigned long	ft_strlen(const char *s);
int				ft_issign(char c);
int				ft_isdigit(char c);
int				ft_isdigits(char *str);
long long		ft_atoll(const char *str);

#endif
