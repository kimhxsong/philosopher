#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "philo.h"

typedef struct s_time {
    struct timeval start;
    struct timeval end;
    int           begin;
    unsigned int  current;
}              t_time;

float   get_elapsed(t_time *time) {
   return (1e+3*(time->end.tv_sec - time->start.tv_sec) + 1e-3*(time->end.tv_usec - time->start.tv_usec));
}

void    print_elapsed(t_time *time) {
    printf("%0.6f\n", \
        1e+3*(time->end.tv_sec - time->start.tv_sec) + 1e-3*(time->end.tv_usec - time->start.tv_usec));
}

const static char *g_usage = \
    "philo: ./philo time_to_die time_to_sleep time_to_eat [max_eat_number]\n";

const static char *g_num_of_philo_zero = \
    "philo: The number of philosophers must be at least one.\n";

const static char *g_alloc_fail = "philo: memory allocation failed\n";



int validate_args(int argc, char *argv[])
{
    int i;

    if (argc == 5 || argc == 6)
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

typedef struct s_routine_args
{
    pthread_mutex_t *forks;
    t_args          *args;
    int             id;
    pthread_mutex_t counter;
    t_time          *time;
}              t_routine_args;

int parse_args(t_args *args, char *argv[])
{
    if (atoi(argv[1]) == 0)
    {
        write(2, g_num_of_philo_zero, 50);
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

void    do_eating(t_args *args, int nth)
{
    usleep(1e+3 * args->time_to_eat);
}

void    do_sleeping(t_args *args, int nth)
{
    usleep(1e+3 * args->time_to_sleep);
}

// void    do_thinking(t_args *args, int nth)
// {
//     printf("%d\t%d\tis thinking\n", 0, nth);
// }

void    *routine(void   *rt_args)
{
    t_routine_args  *rt;
    int even;
    int odd;
    int id;

    rt = (t_routine_args *)rt_args;
    id = rt->id;
    pthread_mutex_unlock(&(rt->counter));
    if (id % 2 == 1)
    {
        odd = id;
        even = odd + 1;
    }    
    else if (id % 2 == 0)
    {
        even = id;
        odd = even + 1;
    }
    while (1)
    {
        printf("%u\t%d\tis thinking\n", rt->time->current, id);
        pthread_mutex_lock(&(rt->forks[even]));
        printf("%u\t%d\thas taken a fork\n", rt->time->current, id);
        pthread_mutex_lock(&(rt->forks[odd]));
        printf("%u\t%d\tis eating.\n", rt->time->current, id);
        do_eating(rt->args, id);
        usleep(rt->args->time_to_eat);
        printf("%u\t%d\tis sleeping\n", rt->time->current, id);
        pthread_mutex_unlock(&(rt->forks[even]));
        pthread_mutex_unlock(&(rt->forks[odd]));
        do_sleeping(rt->args, id);
        usleep(rt->args->time_to_sleep);
    }
    return (NULL);
}

pthread_mutex_t *generate_forks(int number_of_philos)
{
    pthread_mutex_t *forks;
    int             i;

    forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (number_of_philos + 1));
    if (forks == NULL)
        return (NULL);
    i = 0;
    while (i < number_of_philos)
        pthread_mutex_init(&forks[i++], NULL);
    forks[number_of_philos] = forks[0];
    return (forks);
}

pthread_t   *generate_philos(int number_of_philos)
{
    pthread_t   *philos;
    
    philos = (pthread_t *)malloc(sizeof(pthread_t) * number_of_philos);
    return (philos);
}

void *ft_gettime(void *ptr)
{
    t_time *time = (t_time *)ptr;
    struct timeval	tp2;
	unsigned int	r;

	gettimeofday(&tp2, NULL);
	time->current = time->start.tv_sec * 1000 + time->start.tv_usec / 1000;
	time->current = tp2.tv_sec * 1000 + tp2.tv_usec / 1000 - time->current;
    while (1)
    {
        gettimeofday(&tp2, NULL);
	    time->current = time->start.tv_sec * 1000 + time->start.tv_usec / 1000;
	    time->current = tp2.tv_sec * 1000 + tp2.tv_usec / 1000 - time->current;
        usleep(10);
        printf("time : %u\n", time->current);
        
    }
    return ((void *)NULL);
}
void let_dinning(pthread_t *philos, pthread_mutex_t *forks, t_args *args)
{
    t_routine_args  rt_args;
    pthread_mutex_t  t;
    t_time          time;
    pthread_t       time_thread;

    rt_args.forks = forks;
    rt_args.args = args;
    rt_args.id = 0;
    rt_args.time = &time;
    int id;
    id = 0;
    pthread_mutex_init(&(rt_args.counter), NULL);
    pthread_mutex_init(&t, NULL);

    time.current = 0;
    while (id < args->number_of_philos)
    {
        pthread_mutex_lock(&(rt_args.counter));
        rt_args.id = id;
        pthread_create(&philos[id++], NULL, (void *)routine, (void *)&rt_args);
    }
    int fix = 0;
    gettimeofday(&time.start, NULL);
    pthread_create(&time_thread, NULL, (void *)ft_gettime, &time);
    while(1);
}

void end_dinning(pthread_t *philos, pthread_mutex_t *forks, t_args *args)
{
    int i;

    i = 0;
    while (i < args->number_of_philos)
        pthread_join(philos[i++], NULL);
    i = 0;
    while (i <= args->number_of_philos)
        pthread_mutex_unlock(&forks[i++]);
    i = 0;
    while (i <= args->number_of_philos)
        pthread_mutex_destroy(&forks[i++]);
}

int check_if_is_null(void *ptr)
{
    if (ptr == NULL)
    {
        write(2, g_alloc_fail, 32);
        return (TRUE);
    }
    return (FALSE);
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
        return (1);
    if (parse_args(&args, argv) == FAIL)
        return (2);
    if (prepare_dinning(&philos, &forks, &args) == FAIL)
        return (3);
    let_dinning(philos, forks, &args);
    end_dinning(philos, forks, &args);
    // while(1);
    return (0);
}