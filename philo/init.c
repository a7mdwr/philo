/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:10:10 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/15 09:49:55 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

t_philo *philo(t_philo *p, char **av)
{
    p = safe_malloc(sizeof(t_philo) * ft_atoi(av[1]));
    p->died = 0;
    p->share = safe_malloc(sizeof(t_share));
    p->share->philos = ft_atoi(av[1]);
    p->share->time_to_die = ft_atoi(av[2]) * 1000;
    p->share->time_to_eat = ft_atoi(av[3]) * 1000;
    p->share->time_to_sleep = ft_atoi(av[4]) * 1000;
    p->share->starting_time = get_time();
    return (p);
}

void    data_init(t_philo *p)
{
    int i;

    i = 0;
    p->share->forks = safe_malloc(sizeof(pthread_mutex_t) * p->share->philos);
    while (i < p->share->philos)
    {
        pthread_mutex_init(&p->share->forks[i], NULL);
        p[i].share = p->share;
        p[i].left_fork = i;
		p[i].right_fork = (i + 1) % p->share->philos;
        p[i].last_meal = get_time();
        i++;
    }
}