/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterargv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:25:02 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/09 20:54:16 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** ft_iterargv()
** Iterate over argument vetors as argument to is_functions()
*/
int	ft_iterargv(int ac, char *av[], int (isfptr(char *)))
{
	int	i;

	i = 1;
	while (isfptr(av[i]) == 1)
		i++;
	if (i != ac)
		return (0);
	return (1);
}
