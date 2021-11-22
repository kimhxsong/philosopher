/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:16:58 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/22 21:50:33 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_PARSE_H
# define PHILO_PARSE_H

#include "philo.h"

typedef enum  e_state
{
	STATE_ONE_FORK,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_THINKING,
	STATE_DIED,
	STATE_FULL
}	t_state;

typedef struct s_private
{
	t_state			state;
	int				id;
	int				second;
	int				first;
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

typedef struct s_time
{
	struct timeval	tp;
	double			start;
	double			current;
}				t_time;

typedef struct s_shared
{
	pthread_mutex_t	*fork;
	t_time			time;
	t_key			key;
	t_info			info;
	int				finish;
}					t_shared;

typedef struct s_args
{
	t_shared		*s;
	t_private		p;
}					t_args;

typedef struct s_info
{
	int				number_of_philo;
	int				time_of_sleeping;
	int				time_of_eating;
	int				time_to_die;
	unsigned int	max_eat_number;
}					t_info;





int			parse(t_shared *shared, int ac, char *av[]);

#endif
