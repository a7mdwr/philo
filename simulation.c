/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:07:14 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/12 15:58:08 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void *eating_simulation(void *data)
// {
//     t_philo *philo;
    
//     philo = (t_philo *)data;
//     wait_all
// }

void start_simulation(t_philo *p)
{
    int i;
    
    i = 0;
    if (p->share->must_eat == 0)
        return ;
    // else if (s->must_eat == 1)
    else
    {
        while (p->share->philos > i)
        {
            pthread_create(&p[i].thread_id, NULL, &routine, &p[i]);
            p[i].id = i;
            i++;
        }
    }
}