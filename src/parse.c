/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:59:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/23 05:52:31 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

static int	validate_args(int ac, char *av[], int *errnum);
static int	init_info(t_info *info, int ac, char *av[], int *errnum);
static void	assign_info(t_info *info, int ac, char *av[]);
static void	validate_info(t_info *info, int *errnum);

t_shared	*parse(t_shared *s, int ac, char *av[])
{
	int	errnum;

	errnum = 0;
	memset(s, 1, sizeof(t_shared));
	if (validate_args(ac, av, &errnum) || init_info(&s->info, ac, av, &errnum))
	{
		parse_error(errnum - 1);
		return (NULL);
	}
	return (s);
}

static int	validat_args(int ac, char *av[], int *errnum)
{
	if (ac < 5 || ac > 6)
		*errnum = 1;
	else if (ft_strarriter(ac, av, ft_isintf) == -1)
		*errnum = 2;
	return (*errnum);
}

static int	init_info(t_info *info, int ac, char *av[], int *errnum)
{
	assign_info(info, ac, av);
	validate_info(info, errnum);
	return (*errnum);
}

static void	assign_info(t_info *info, int ac, char *av[])
{
	info->number_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_of_sleeping = ft_atoi(av[3]);
	info->time_of_eating = ft_atoi(av[4]);
	info->max_eat_number = ft_ternaryint(ac == 6, ft_atoi(av[5]), -1);
}

static void	validate_info(t_info *info, int *errnum)
{
	if ((info->number_of_philo <= 0) || (info->max_eat_number <= 0)
		|| (info->time_to_die < 0) || (info->time_of_eating < 0)
		|| (info->time_of_sleeping < 0))
		*errnum = 3;
}
