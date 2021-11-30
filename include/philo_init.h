/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:16:58 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/30 22:23:59 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_INIT_H
# define PHILO_INIT_H

# include "philo.h"

typedef enum e_state {
	STATE_ONE_FORK,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_THINKING,
	STATE_DIED,
	STATE_FULL
}	t_state;

typedef struct s_info {
	int	number_of_philo;
	int	time_of_sleeping;
	int	time_of_eating;
	int	time_to_die;
	int	is_max_used;
	int	max_eat_number;
}	t_info;

typedef struct s_private
{
	int				id;
	t_state			state;
	pthread_mutex_t	*second;
	pthread_mutex_t *first;
	int				time_of_thread;
	int				time_to_die;
	int				num_of_eat;
	int				end_of_eating;
	int				end_of_sleeping;
}	t_private;

typedef struct s_key
{
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	order;
}	t_key;

typedef struct s_clock
{
	struct timeval	tp;
	double			start;
	double			current;
}	t_clock;

typedef struct s_shared {
	pthread_mutex_t	*forks;
	t_clock			clock;
	t_key			key;
	int				is_finished;
	int				errnum;
	int				info[5];
}	t_shared;

typedef struct s_data {
	t_shared	*s;
	t_private	p;
}	t_data;

t_data	*init(t_shared *shared, int argc, char **argv);

#endif
