/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:28:30 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 04:35:30 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "philo_error.h"

int main(void)
{
	for(int i = 0; i < 3; i++)
		ft_perror("test", g_err, i);
	ft_perror(NULL, g_err, 0);
	ft_perror("test", NULL, 0);
	ft_perror("test", g_err, -1);
	ft_perror("test", NULL, -1);
	return (0);
}