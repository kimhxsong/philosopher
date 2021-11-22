/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:59:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/12 02:51:51 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** init_shared()
** Initialize t_shared struct with argument vectors
*/
static int	init_shared(int ac, char *av[], t_shared *shared)
{
	int	res;

	shared->finish = 0;
	shared->time.current = 0;
	shared->info.max_eat_number = -1;
	shared->info.number_of_philo = atoi(av[1]);
	if (shared->info.number_of_philo > PTHREAD_STACK_MIN / 2)
		return (FAIL);
	shared->info.time_to_die = atoi(av[2]);
	shared->info.time_of_sleeping = atoi(av[3]);
	shared->info.time_of_eating = atoi(av[4]);
	if (av[5] != NULL)
		shared->info.max_eat_number = atoi(av[5]);
	res = shared->info.number_of_philo <= 0 \
		|| shared->info.time_to_die < 20 \
		|| shared->info.time_of_sleeping < 20 \
		|| shared->info.time_of_eating < 20 \
		|| shared->info.max_eat_number <= 0;
	if (res != 0)
		return (FAIL);
	res = shared->info.time_of_eating - shared->info.time_of_sleeping;
	return (SUCCESS);
}

/*
** parse()
** Check if vectors are valid integer formats
** Parse argument to t_shared variable
*/
int	parse(t_shared *shared, int ac, char *av[])
{
	int	idx;

	if (ac != 5 && ac != 6)
		return (1);
	else if (ft_iterargv(ac, av, ft_isintf) == FAIL)
		return (2);
	else if (init_shared(ac, av, shared) == FAIL)
		return (3);
	else
		return (0);
}
