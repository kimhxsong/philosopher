/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:59:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/10 13:42:46 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_shared(int ac, char *av[], t_shared *shared);

/*
** parse()
** Check if vectors are valid integer formats
** Parse argument to t_shared variable
*/
int	parse(t_shared *shared, int ac, char *av[])
{
	if (ac == 5 || ac == 6)
		if (ft_iterargv(ac, av, ft_isintf) == SUCCESS)
			if (init_shared(ac, av, shared) == SUCCESS)
				return (SUCCESS);
	return (FAIL);
}

/*
** init_shared()
** Initialize t_shared struct with argument vectors
*/
static int	init_shared(int ac, char *av[], t_shared *shared)
{
	shared->info.time_of_main = 0;
	shared->info.someone_died = 0;
	shared->info.number_of_philo = atoi(av[1]);
	if (shared->info.number_of_philo > PTHREAD_STACK_MIN / 2)
		return (FAIL);
	shared->info.time_to_die = atoi(av[2]);
	shared->info.time_of_sleeping = atoi(av[3]);
	shared->info.time_of_eating = atoi(av[4]);
	shared->info.max_eat_number = atoi(av[5]);
	if (shared->info.time_to_die < 20 \
		|| shared->info.time_of_sleeping < 20 \
		|| shared->info.time_of_eating < 20 \
		|| shared->info.max_eat_number <= 0)
		return (FAIL);
	return (SUCCESS);
}
