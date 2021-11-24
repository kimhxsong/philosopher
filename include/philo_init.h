/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:16:58 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/11/24 17:27:15 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_INIT_H
# define PHILO_INIT_H

# include "philo.h"

typedef enum e_state {
	STATE_THINKING,
	STATE_ONE_FORK,
	STATE_EATING,
	STATE_SLEEPING,
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
	t_state	state;
	int		id;
	int		second;
	int		first;
	int		time_of_thread;
	int		time_to_die;
	int		num_of_eat;
	int		end_of_eating;
	int		end_of_sleeping;
}	t_private;

typedef struct s_key
{
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	order;
}	t_key;

typedef struct s_time
{
	struct timeval	tp;
	double			start;
	double			current;
}	t_time;

typedef struct s_shared {
	pthread_mutex_t	*fork;
	t_time			time;
	t_key			key;
	t_info			info;
	int				finish;
}	t_shared;

typedef struct s_data {
	t_shared	*s;
	t_private	p;
	int			errnum;
}	t_data;

t_shared	*init(t_shared *shared, int argc, char **argv);
int			init_shared(t_shared *shared, int argc, char **argv);
int			init_private(t_data **data, t_shared *shared);

#endif
