/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:34:23 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 05:32:55 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  UTIL_H
# define UTIL_H

# include <stdlib.h>
# include <unistd.h>
/*
 *	string.h
 */
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
size_t		ft_strspn(const char *s, const char *charset);

/*
 *  cytpe.h
 */
int			ft_isdigit(int c);
int			ft_isspace(int c);

/*
 * stdlib.h
 */
int			ft_atoi(const char *s);
long long	ft_atoll(const char *s);

#endif
