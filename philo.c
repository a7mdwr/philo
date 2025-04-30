#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"

int    init_threads(t_philo *s)
{
    s->philos = ft_atoi(s->array[1]);
    s->time_to_die = ft_atoi(s->array[2]);
    s->time_to_eat = ft_atoi(s->array[3]);
    s->time_to_sleep = ft_atoi(s->array[4]);
    printf("%d\n", s->time_to_sleep);
    if (!s->philos || !s->time_to_die || !s->time_to_eat || !s->time_to_sleep)
        return (perror("Error: Values must be > 0"), 0);
    if (s->array[5])
    {
        s->must_eat = ft_atoi(s->array[5]);
        if (s->must_eat <= 0)
            return (perror("Error: (must_eat) must be > 0"), 0);
    }
    else
        s->must_eat = -1;
    return (1);
}


int main(int ac, char **av)
{
    t_philo s;
    int j;

    j = 0;
    ft_bzero(&s, sizeof(t_philo));
    if (ac != 5 && ac != 6)
        return(perror("Error: wrong number of arguments"), 0);
    if(!check(&s, av, ac) || !init_threads(&s))
        return(0);
    
}
