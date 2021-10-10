/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:46:41 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/10 16:31:59 by hyeonsok         ###   ########.fr       */
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
	double			start;
}				t_time;

typedef enum  e_state
{
	STATE_ONE_FORK,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_THINKING,
	STATE_DIED,
	STATE_FULL
}	t_state;

typedef struct s_info
{
	int				number_of_philo;
	int				time_of_sleeping;
	int				time_of_eating;
	int				time_to_die;
	unsigned int	max_eat_number;
	double			time_of_main;
	int				finish;
}					t_info;

typedef struct s_private
{
	t_state			state;
	int				id;
	int				even;
	int				odd;
	int				time_of_thread;
	int				time_to_die;
	int				num_of_eat;
	int				end_of_eating;
	int				end_of_sleeping;
}					t_private;

typedef struct s_key
{
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	order;
}					t_key;

typedef struct s_shared
{
	pthread_mutex_t	*fork;
	t_time			time;
	t_key			key;
	t_info			info;
}					t_shared;

typedef struct s_args
{
	t_shared		*s;
	t_private		p;
}					t_args;

/*
**	routines in time.c, dining.c and watch.c
*/
void		*routine_clock(void *shared);
void		*routine_dining(void *args);
void		*routine_watch(void *args);

/*
**	time.c
*/

int			init_time(t_shared *shared);
void		update_time(t_shared *shared);

/*
**	parse.c
*/
int			parse(t_shared *shared, int ac, char *av[]);

/*
**	print.c
*/
int			print_state(t_args *args);
#endif
