/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:10:10 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/12 13:57:56 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

static void assign_forks(t_philo *philo, t_fork *forks, int position)
{
    int philo_nbr;

    philo_nbr = philo->share->philos;
    if (philo->id % 2 == 0)
    {
        philo->right_fork = &forks[position];
        philo->left_fork = &forks[(position + 1) % philo_nbr];
    }
}
static void philo_init(t_share *s)
{
    int i;
    t_philo *philo;
    
    i = 0;
    while(i < s->philos)
    {
        philo = s->philos + i;
        philo->id =  i + 1;
        philo->full = false;
        philo->meals_count = 0;
        philo->share = s;
        
        assign_foks(philo, s->forks, i);
    }
}

void    data_init(t_share *s)
{
    int i;

    i = 0;
    s->end_simulation = false;
    s->all_philos_ready = false;
    s->philos = ft_malloc(sizeof(t_philo) * s->philos);
    s ->forks = ft_malloc(sizeof(pthread_mutex_t) * s->philos);
    while (i < s->philos)
    {
        pthread_mutex_init(&s->forks[i].fork_id, NULL);
        s->forks[i].fork_id = i;
        i++;
    }
}