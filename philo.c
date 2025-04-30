#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"

// void    init_threads(t_philo *s)
// {
//     s->philos = ft_atoi(s->array[1]);
//     s->time_to_die = ft_atoi(s->array[2]);
//     s->time_to_eat = ft_atoi(s->array[3]);
//     s->time_to_sleep = ft_atoi(s->array[4]);

// }


int main(int ac, char **av)
{
    t_philo s;
    int j;

    j = 0;
    ft_bzero(&s, sizeof(t_philo));
    if (ac != 5 && ac != 6)
        return(perror("error : argments invalid"), 0);
    if(!check(&s, av, ac))
        return(perror("error "), 0);
    
}
