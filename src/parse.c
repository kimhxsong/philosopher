/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:59:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 09:17:05 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

static int	validate_args(int ac, char *av[], int *nerr);
static int	init_info(t_info *info, int ac, char *av[], int *nerr);
static void	assign_info(t_info *info, int ac, char *av[]);
static void	validate_info(t_info *info, int *nerr);

t_shared	*parse(t_shared *s, int ac, char *av[])
{
	int	nerr;

	nerr = 0;
	ft_memset(s, 0, sizeof(t_shared));
	if (validate_args(ac, av, &nerr) || init_info(&s->info, ac, av, &nerr))
	{
		parse_error(nerr - 1);
		return (NULL);
	}
	return (s);
}

static int	validate_args(int ac, char *av[], int *nerr)
{
	if (ac < 5 || ac > 6)
		*nerr = 1;
	else if (ft_strarriter(ac, av, ft_isintf) == -1)
		*nerr = 2;
	return (*nerr);
}

static int	init_info(t_info *info, int ac, char *av[], int *nerr)
{
	assign_info(info, ac, av);
	validate_info(info, nerr);
	return (*nerr);
}

static void	assign_info(t_info *info, int ac, char *av[])
{
	info->number_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_of_sleeping = ft_atoi(av[3]);
	info->time_of_eating = ft_atoi(av[4]);
	if (ac == 6)
	{
		info->is_max_used = 1;
		info->max_eat_number = ft_atoi(av[5]);
	}
}

static void	validate_info(t_info *info, int *nerr)
{
	if ((info->is_max_used && info->max_eat_number <= 0) \
		|| (info->number_of_philo <= 0) || (info->time_to_die < 0) \
		|| (info->time_of_eating < 0) || (info->time_of_sleeping < 0))
		*nerr = 3;
}
