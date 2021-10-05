/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:59:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/06 03:21:57 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_shared(int ac, char *av[], t_shared *shared);

/*
** parse()
** check Are vectors valid integer formats
** parse argument to t_shared variable
*/
int	parse(t_args *args, int ac, char *av[])
{
	if (ac >= 4 && ac <= 5)
		if (ft_iterargv(ac, av, ft_isif) == SUCCESS)
			if (init_shared(ac, av, &args->shared) == SUCCESS)
				return (SUCCESS);
	return (FAIL);
}

/*
** init_shared()
** Initialize t_shared struct with argument vectors
*/
static int	init_shared(int ac, char *av[], t_shared *shared)
{
	shared->time_of_main = 0;
	shared->someone_died = 0;
	shared->number_of_philo = atoi(av[1]);
	if (shared->number_of_philo > PTHREAD_STACK_MIN / 2)
		return (FAIL);
	shared->time_to_die = atoi(av[2]);
	shared->time_of_sleeping = atoi(av[3]);
	shared->time_of_eating = atoi(av[4]);
	shared->max_eat_number = atoi(av[5]);
	if (shared->time_to_die < 20 || \
		shared->time_of_sleeping < 20 || \
		shared->time_of_eating < 20 || \
		shared->max_eat_number <= 0)
		return (FAIL);
	return (SUCCESS);
}
