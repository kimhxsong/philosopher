#ifndef PHILO_H
# define PHILO_H

# define FALSE 0
# define TRUE 1
# define SUCCESS 0
# define FAIL 1

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_time
{
	struct timeval	tp;
}				t_time;

typedef struct s_shared
{
	const int	time_of_sleeping;
	const int	time_of_eating;
	const int	time_to_die;
	const int	max_eat_number;
	int			time_of_main;
	int			someone_died;
}				t_shared;

typedef struct s_private
{
	const int	id;
	int			state;
	int			time_of_thread;
	int			time_to_die;
}				t_private;

typedef struct s_key
{
	pthread_mutex_t	print;
	pthread_mutex_t	death;
}				t_key;

typedef struct s_args
{
	t_shared	*shared;
	t_private	*private;
	t_time		*time;
	t_key		*key;
}				t_args;

enum	e_stat
{
	thinking,
	eating,
	sleeping,
	died
};

/*
**	time.c
*/
void	*update_time(t_args *args);

/*
** utils.c
*/
int		ft_issign(char c);
int		ft_isdigit(char c);
int		ft_isdigits(char *str);

#endif
