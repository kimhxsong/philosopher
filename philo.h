/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:46:41 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/05 21:06:22 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include "utils.h"

//will be removed before evaluating
# include <string.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL -1

typedef struct s_time
{
	struct timeval	tp;
	unsigned int	start;
}				t_time;

typedef struct s_shared
{
	int			number_of_philo;
	int			time_of_sleeping;
	int			time_of_eating;
	int			time_to_die;
	int			max_eat_number;
	int			time_of_main;
	int			someone_died;
}				t_shared;

typedef struct s_private
{
	int			id;
	int			state;
	int			time_of_thread;
	int			time_to_die;
}				t_private;

typedef struct s_key
{
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	clock;
}				t_key;

typedef struct s_args
{
	t_shared	shared;
	t_private	private;
	t_time		time;
	t_key		key;
}				t_args;

/*
**	time.c
*/
void		*routine_clock(t_args *args);

#endif
