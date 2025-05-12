/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:21:25 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/12 16:18:44 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

static t_philo *philo(t_philo *p, char **av)
{
    p = ft_malloc(sizeof(t_philo) * ft_atoi(av[1]));
    p->share = ft_malloc(sizeof(t_share));
    p->share->philos = ft_atoi(av[1]);
    p->share->time_to_die = ft_atoi(av[2]) * 1000;
    p->share->time_to_eat = ft_atoi(av[3]) * 1000;
    p->share->time_to_sleep = ft_atoi(av[4]) * 1000;
    return (p);
}
int main(int ac, char **av)
{
    t_philo *p;
    int i;

    i = 0;
    p = NULL;
    // ft_bzero(p, sizeof(t_philo));
    p = philo(p, av);
    if(!check(av, ac) || !parsing(p, av))
        return(0);
    data_init(p);
    start_simulation(p);
}