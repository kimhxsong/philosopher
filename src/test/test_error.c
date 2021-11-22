/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:28:30 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 05:13:52 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(void)
{
	for(int i = 0; i < 3; i++)
		ft_error("test", g_err, i);
	//expect NO SEGV
	ft_error(NULL, g_err, 0);
	//expect SEGV
	ft_error("test", NULL, 0);
	ft_error("test", g_err, -1);
	ft_error("test", NULL, -1);
	return (0);
}