/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:43:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/30 16:43:04 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_validate.h"

void	*safe_malloc(size_t len)
{
	void	*ptr;

	ptr = malloc(len);
	if (!ptr)
	{
		write(2, "fatol error", 11);
		exit(1);
	}
	ft_memset(ptr, 0, len);
	return (ptr);
}

int	validate_argv(int argc, char *argv[])
{
	if (!argv || ft_strarriter(argc - 1, &argv[1], ft_isintf))
		return (-1);
	return (0);
}

int	validate_argc(int argc)
{
	if (argc < 5 || argc > 6)
		return (-1);
	return (0);
}