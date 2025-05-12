/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:21:12 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/12 10:19:07 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
    t_share *s = (t_share *)arg;
    while (1)
    {
        printf("philo number %d is thinking", s->philos);
        printf("philo number %d has taken a fork", s->philos);
        pthread_mutex_lock(s->left_fork);
        pthread_mutex_lock(s->right_fork);
        printf("philo number %d is eating", s->philos);
        usleep(s->time_to_eat);
        pthread_mutex_unlock(s->left_fork);
        pthread_mutex_unlock(s->right_fork);
        printf("philo number %d is sleeping", s->philos);
        usleep(s->time_to_sleep);
        
    }
    return NULL;
}