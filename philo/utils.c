#include "philo.h"

int ft_issign(char c)
{
    return (c == '+' || c == '-');
}

int ft_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

int ft_isdigits(char *str)
{
    int i;

    i = 0;
    while (ft_isdigit(str[i]))
        i++;
    if (i != 0 && str[i] == '\0')
        return (TRUE);
    return (FALSE);
}
