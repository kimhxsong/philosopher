/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:43:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/12/11 15:34:38 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_validate.h"

void	*custom_malloc(size_t len)
{
	void	*ptr;

	ptr = malloc(len);
	if (!ptr)
	{
		write(2, "fatol error: memory allocation failed.", 39);
		return (NULL);
	}
	memset(ptr, 0, len);
	return (ptr);
}

int	validate_argv(int argc, char *argv[])
{
	if (!argv || ft_strarriter(argc - 1, &argv[1], ft_isintf))
	{
		ft_error("validate_argv", g_err, 1);
		return (-1);
	}
	return (0);
}

int	validate_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_error("validate_argc", g_err, 0);
		return (-1);
	}
	return (0);
}