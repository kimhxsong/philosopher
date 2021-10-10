/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:59:09 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/10 15:58:06 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_error(int	myerrno)
{
	const char	*msg[3] = \
	{
		"parse: too few arguments or too many arguments\n", \
		"parse: not in int format. \"[-,+][n zeros][int_min ~ int_max]\"\n", \
		"parse: argument value too small or negative"\
	};

	if (myerrno < 0 || myerrno > 2)
		return (FAIL);
	printf("%s", msg[myerrno]);
	return (SUCCESS);
}

/*
** init_shared()
** Initialize t_shared struct with argument vectors
*/
static int	init_shared(int ac, char *av[], t_shared *shared)
{
	shared->info.time_of_main = 0;
	shared->info.finish = 0;
	shared->info.max_eat_number = -1;
	shared->info.number_of_philo = atoi(av[1]);
	if (shared->info.number_of_philo > PTHREAD_STACK_MIN / 2)
		return (FAIL);
	shared->info.time_to_die = atoi(av[2]);
	shared->info.time_of_sleeping = atoi(av[3]);
	shared->info.time_of_eating = atoi(av[4]);
	if (av[5] != NULL)
		shared->info.max_eat_number = atoi(av[5]);
	if (shared->info.time_to_die < 20 \
		|| shared->info.time_of_sleeping < 20 \
		|| shared->info.time_of_eating < 20 \
		|| shared->info.max_eat_number <= 0)
		return (FAIL);
	return (SUCCESS);
}

/*
** parse()
** Check if vectors are valid integer formats
** Parse argument to t_shared variable
*/
int	parse(t_shared *shared, int ac, char *av[])
{
	int	err;

	if (ac != 5 && ac != 6)
		err = 0;
	else if (ft_iterargv(ac, av, ft_isintf) == FAIL)
		err = 1;
	else if (init_shared(ac, av, shared) == FAIL)
		err = 2;
	else
		return (SUCCESS);
	print_error(err);
	return (FAIL);
}
