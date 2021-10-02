#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

const static char *g_usage = \
    "philo: ./philo time_to_die time_to_sleep time_to_eat [max_eat_number]\n";

const static char *g_num_of_philo_zero = \
    "philo: The number of philosophers must be at least one.\n";

const static char *g_alloc_fail = "philo: memory allocation failed\n";



int validate_args(int argc, char *argv[])
{
    int i;

    if (argc != 5 && argc != 6)
    {
        i = 1;
        while (i < argc)
        {
            if (ft_isdigits(argv[i]) == FALSE)
                break ;
            i++;
        }
        return (TRUE);
    }
    write(2, g_usage, 70);
    return (FALSE);
}

enum e_stat
{
    thinking,
    eating,
    sleeping,
    died
};

typedef struct s_args
{
    int          number_of_philos;
    int          time_to_die;
    int          time_to_sleep;
    int          time_to_eat;
    int          max_eat_number;
}              t_args;

typedef struct s_philo
{
    enum e_stat stat;
    t_args      args;
    
}           t_philo;

int parse_args(t_args *args, char *argv[])
{
    if (atoi(argv[1]) == 0)
    {
        write(2, g_num_of_philo_zero, 49);
        return(FAIL);
    }
    args->number_of_philos = atoi(argv[1]);
    args->time_to_die = atoi(argv[2]);
    args->time_to_sleep = atoi(argv[3]);
    args->time_to_eat = atoi(argv[4]);
    if (argv[5] != NULL)
        args->max_eat_number = atoi(argv[5]);
    return (SUCCESS);
}

void    *print_args(t_args *args)
{
    printf("==== Arguments Table ====\n");
    printf("number_of_philos: %d\n",args->number_of_philos);
    printf("time to die\t: %d\n", args->time_to_die);
    printf("time_to_sleep\t: %d\n", args->time_to_sleep);
    printf("time_to_eat\t: %d\n", args->time_to_eat);
    printf("max_eat_number\t: %d\n\n", args->max_eat_number);
    return (NULL);
}

void    *routine_odd(void)
{
    while (1)
    {
        // get_left_fork();
        // lock_fork();
        // get_right_fork();
        // lock_fork();
        // do_eating();
        // unlock_forks();
        // do_sleeping();
        // do_thinking();
    }
    return (NULL);
}

void    *routine_even(void)
{
    while (1)
    {
        // get_right_fork();
        // lock_fork();
        // get_left_fork();
        // lock_fork();
        // do_eating();
        // unlock_forks();
        // do_sleeping();
        // do_thinking();
    }
    return (NULL);
}

pthread_mutex_t *generate_forks(int number_of_philos)
{
    pthread_mutex_t *forks;
    int             i;

    forks = (pthread_mutex_t *)malloc(sizeof(pthread_t) * number_of_philos);
    if (forks == NULL)
        return (NULL);
    i = 0;
    while (i < number_of_philos)
        pthread_mutex_init(&forks[i++], NULL);
    return (forks);
}

pthread_t   *generate_philos(int number_of_philos)
{
    pthread_t   *philos;
    
    philos = (pthread_t *)malloc(sizeof(pthread_t) * number_of_philos);
    return (philos);
}

void let_dinning(pthread_t *philos, pthread_mutex_t *forks, t_args *args)
{
    int i;

    i = 0;
    while(i < args->number_of_philos)
    {
        if (i % 2 == 1)
            pthread_create(&philos[i], NULL, (void *)routine_odd, NULL);
        else
            pthread_create(&philos[i], NULL, (void *)routine_even, NULL);
    }
}

void end_dinning(pthread_t *philos, pthread_mutex_t *forks, t_args *args)
{
    int i;

    i = 0;
    while (i < args->number_of_philos)
        pthread_join(philos[i++], NULL);
    i = 0;
    while (i < args->number_of_philos)
        pthread_mutex_destroy(&fork[i++]);
}

int check_if_is_null(void *ptr)
{
    if (ptr == NULL)
    {
        write(2, g_alloc_fail, 32);
        return (0);
    }
    return (1);
}

int prepare_dinning(pthread_t **philos, pthread_mutex_t **forks, t_args *args)
{
    *philos = generate_philos(args->number_of_philos);
    *forks = generate_forks(args->number_of_philos);
    if (check_if_is_null(*philos) == TRUE || check_if_is_null(*forks) == TRUE)
        return (FAIL);
    return (SUCCESS);
}

int main(int argc, char *argv[])
{
    pthread_t       *philos;
    pthread_mutex_t *forks;
    t_args          args;
    int             i;

    if (validate_args(argc, argv) == FALSE)
        return (FAIL);
    if (parse_args(&args, argv) == FAIL)
        return (FAIL);
    if (prepare_dinning(&philos, &forks, &args) == FAIL)
        return (FAIL);
    let_dinning(philos, forks, &args);
    end_dinning(philos, forks, &args);
    return (0);
}
