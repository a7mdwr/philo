/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:21:25 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/06 20:09:19 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int    init_threads(t_philo *s, char **av)
{
    s->shared->philos = ft_atoi(s->av[1]);
    s->shared->time_to_die = ft_atoi(s->av[2]);
    s->shared->time_to_eat = ft_atoi(s->av[3]);
    s->shared->time_to_sleep = ft_atoi(s->av[4]);
    s->shared->forks = ft_malloc(sizeof(t_mtx) * s->shared->philos);
    pthread_mutex_init(s->shared->left_fork, NULL);
    pthread_mutex_init(s->shared->right_fork, NULL);
    if (!s->shared->philos || !s->shared->time_to_die || !s->shared->time_to_eat|| !s->shared->time_to_sleep)
        return (error_exit("Error: Values must be > 0"), 0);
    if (s->av[5])
    {
        s->shared->must_eat = ft_atoi(s->av[5]);
        if (s->shared->must_eat <= 0)
            return (error_exit("Error: (must_eat) must be > 0"), 0);
    }
    else
        s->shared->must_eat = -1;
    return (1);
}


int main(int ac, char **av)
{
    t_philo s;
    t_share p;
    pthread_t *threads;
    int i;

    i = 0;
    ft_bzero(&s, sizeof(t_philo));
    if (ac != 5 && ac != 6)
    return(error_exit("Error: wrong number of arguments"), 0);
    if(!check(&s, av, ac) || !init_threads(&s, av))
    return(0);
    threads = malloc(sizeof(pthread_t) * p.philos);
    while(i < p.philos)
    {
        if(pthread_create(&threads[i], NULL, &routine, NULL) != 0)
            return (error_exit("Error : faild to creat thread"), 0);
        i++;
    }
    i = 0;
    while(i < p.philos)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
    free(threads);
}