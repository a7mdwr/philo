/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:21:12 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/16 18:42:18 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
    t_philo *s = (t_philo *)arg;
    while (1)
    {
        if (s->share->died == 1)
            return NULL;
        printf("philo number %d is thinking\n", s->id);
        pthread_mutex_lock(&s->share->forks[s->left_fork]);
        pthread_mutex_lock(&s->share->forks[s->right_fork]);
        if (s->share->died == 1)
        {
            pthread_mutex_unlock(&s->share->forks[s->left_fork]);
            pthread_mutex_unlock(&s->share->forks[s->right_fork]);
            return NULL;
        }
        printf("philo number %d has taken a fork\n", s->id);
        printf("philo number %d is eating\n", s->id);
        usleep(s->share->time_to_eat);
        if (s->share->died == 1)
        {
            pthread_mutex_unlock(&s->share->forks[s->left_fork]);
            pthread_mutex_unlock(&s->share->forks[s->right_fork]);
            return NULL;
        }
        pthread_mutex_unlock(&s->share->forks[s->left_fork]);
        pthread_mutex_unlock(&s->share->forks[s->right_fork]);
        s->last_meal = get_time();
        printf("philo number %d is sleeping\n", s->id);
        usleep(s->share->time_to_sleep);
        if (s->share->died == 1)
            return NULL;
    }
    
    return NULL;
}