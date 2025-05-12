/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:07:14 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/12 13:56:47 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *eating_simulation(void *data)
{
    t_philo *philo;
    
    philo = (t_philo *)data;
    wait_all
}

void start_eat(t_share *s)
{
    int i;

    i = 0;
    if (s->must_eat == 0)
        return ;
    // else if (s->must_eat == 1)
    else
    {
        while (s->philos > i)
        {
            pthread_create(&s->philo[i].thread_id, eating_simulation, );
            i++;
        }
    }
    
}