/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:07:14 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/14 20:18:39 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_for_die(t_philo *p)
{
    int i;
    int time;

    i = 0;
    time = 0;
    while(p->share->philos > i)
    {
        time = get_time() - p->starting - p->last_meal;
        if(time > p->share->time_to_die)
        {
            p->died = 1;
        }
    }
}

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
            p[i].id = i;
            pthread_create(&p[i].thread_id, NULL, &routine, &p[i]);
            i++;
        }
    }
}