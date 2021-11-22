/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:34:23 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/22 20:21:12 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __UTIL_H__
# define __UTIL_H__

# include <stdlib.h>
/*
 *	string.h
 */
size_t		ft_strlen(const char *s);
size_t		ft_strchr(const char *s, int c);
size_t		ft_strspn(const char *s, const char *charset);

/*
 *  cytpe.h
 */
int			ft_isdigit(int c);
int			ft_isspace(int c);

/*
 * stdlib.h
 */
long long	ft_atoll(const char *s);

#endif
