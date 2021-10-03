#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_time {
    struct timeval start;
    struct timeval end;
}              t_time;

float   get_elapsed(t_time *time) {
   return (time->end.tv_sec - time->start.tv_sec + 1e-6*(time->end.tv_usec - time->start.tv_usec));
}

void    print_elapsed(t_time *time) {
    printf("%0.6f\n", \
        time->end.tv_sec - time->start.tv_sec + 1e-6*(time->end.tv_usec - time->start.tv_usec));
}

int main(void)
{
    t_time time;

    gettimeofday(&time.start, NULL);
    usleep(1e+6);
    gettimeofday(&time.end, NULL);
    print_elapsed(&time);
    printf("%f\n", get_elapsed(&time));
}
