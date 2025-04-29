#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"

int main(int ac, char **av)
{
    t_philo s;
    int j;

    j = 1;
    ft_bzero(&s, sizeof(t_philo));
    if (ac != 5 && ac != 6)
        return(perror("error : argments invalid"), 0);
    if(!check(&s, av, ac))
        return(perror("error "), 0);
    if (j == ac)
        s.philos = 
}
