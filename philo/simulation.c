/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:43:06 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/24 19:07:36 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_for_die(t_philo *p)
{
    int i = 0;
    long long time;

    while (i < p->share->philos)
    {
        time = get_time() - p[i].last_meal;
        if (time > p[i].share->time_to_die)
        {
            if(p->share->must_eat > 0)
            {
                printf("Philo %d died after %lldms\n", p[i].id, get_time() - p->share->starting_time);
                p->share->died = 1;   
            }
            return 0;
        }
        i++;
    }
    return 1;
}


void start_simulation(t_philo *p)
{
    int i;
    
    i = 0;
    while (p->share->philos > i)
    {
        p[i].id = i + 1;
        int r = pthread_create(&p[i].thread_id, NULL, &routine, &p[i]);
        if (r != 0)
            printf("faild");
        usleep(100);
        i++;
    }
}
