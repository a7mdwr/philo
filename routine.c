/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:21:12 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/12 16:19:47 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
    t_philo *s = (t_philo *)arg;
    while (1)
    {
        printf("philo number %d is thinking\n", s->id);
        printf("philo number %d has taken a fork\n", s->id);
        // printf("---->%d\n", s->right_fork);
        pthread_mutex_lock(&s->share->forks[s->left_fork]);
        pthread_mutex_lock(&s->share->forks[s->right_fork]);
        printf("philo number %d is eating\n", s->id);
        usleep(s->share->time_to_eat);
        pthread_mutex_unlock(&s->share->forks[s->left_fork]);
        pthread_mutex_unlock(&s->share->forks[s->right_fork]);
        printf("philo number %d is sleeping\n", s->id);
        usleep(s->share->time_to_sleep);
    }
    return NULL;
}