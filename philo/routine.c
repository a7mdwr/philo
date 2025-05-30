/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:21:12 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/29 18:14:10 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void *routine(void *arg)
{
    t_philo *s = (t_philo *)arg;
    int i;
    i = s->share->must_eat;
    while (i != 0)
    {
        printf("--------------->%d\n", s->share->must_eat);
        if (s->share->died == 1)
            return NULL;
        pthread_mutex_lock(s->share->print);
        printf("%lld philo number %d is thinking\n", get_time() - s->share->starting_time, s->id);
        pthread_mutex_unlock(s->share->print);
        pthread_mutex_lock(&s->share->forks[s->left_fork]);
        pthread_mutex_lock(&s->share->forks[s->right_fork]);
        if (s->share->died == 1)
        {
            pthread_mutex_unlock(&s->share->forks[s->left_fork]);
            pthread_mutex_unlock(&s->share->forks[s->right_fork]);
            return NULL;
        }
        pthread_mutex_lock(s->share->print);
        printf("%lld philo number %d has taken a left fork\n", get_time() - s->share->starting_time, s->id);
        pthread_mutex_unlock(s->share->print);
        pthread_mutex_lock(s->share->print);
        printf("%lld philo number %d has taken a right fork\n", get_time() - s->share->starting_time, s->id);
        pthread_mutex_unlock(s->share->print);
        pthread_mutex_lock(s->share->print);
        printf("%lld philo number %d is eating\n",get_time() - s->share->starting_time , s->id);
        pthread_mutex_unlock(s->share->print);
        sleeper(s->share->time_to_eat);
        pthread_mutex_lock(s->share->meal_mtx);
        i--;
        pthread_mutex_unlock(s->share->meal_mtx);
        if (s->share->died == 1)
        {
            pthread_mutex_unlock(&s->share->forks[s->left_fork]);
            pthread_mutex_unlock(&s->share->forks[s->right_fork]);
            return NULL;
        }
        pthread_mutex_unlock(&s->share->forks[s->left_fork]);
        pthread_mutex_unlock(&s->share->forks[s->right_fork]);
        s->last_meal = get_time();
        pthread_mutex_lock(s->share->print);
        printf("%lld philo number %d is sleeping\n",get_time() - s->share->starting_time, s->id);
        pthread_mutex_unlock(s->share->print);
        sleeper(s->share->time_to_sleep);
        pthread_mutex_lock(s->share->mtx_died);
        if (s->share->died == 1)
            return NULL;
        pthread_mutex_unlock(s->share->mtx_died);
    }
    s->share->must_eat = i;
    return NULL;
}