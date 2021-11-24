/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:50:43 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/24 17:34:18 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	validate_argv(int argc, char *argv[])
{
	return (ft_strarriter(argc, argv, ft_isintf) == -1);
}

static int	validate_argc(int argc)
{
	return (argc < 5 || argc > 6);
}

static int	validate(int argc, char *argv[])
{
	return (validate_argc(argc) || validate_argv(argc, argv));
}

/**
 * TODO: Handle when init fails
 */
t_shared	*init(t_shared *shared, int argc, char **argv)
{
	t_data	*data;

	if (validate(argc, argv) == FAIL
		|| init_shared(shared, argc, argv) == FAIL
		|| init_private(&data, shared) == FAIL)
		return (NULL);
	return (&data);
}
