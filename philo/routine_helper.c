/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:06:06 by aradwan           #+#    #+#             */
/*   Updated: 2025/06/02 18:59:00 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_forks(t_philo *s)
{
	pthread_mutex_unlock(&s->share->forks[s->left_fork]);
	pthread_mutex_unlock(&s->share->forks[s->right_fork]);
}

void	sleep_philo(t_philo *s)
{
	print_action(s, "is sleeping");
	sleeper(s->share->time_to_sleep);
}

void	*routine(void *arg)
{
	t_philo	*s;
	int		meals;

	s = (t_philo *)arg;
	meals = s->share->must_eat;
	while (meals != 0)
	{
		if (check_death(s))
			return (NULL);
		think(s);
		if (!take_forks(s))
			return (NULL);
		if (!eat(s, &meals))
			return (NULL);
		drop_forks(s);
		if (check_death(s))
			return (NULL);
		sleep_philo(s);
	}
	s->share->must_eat = meals;
	return (NULL);
}
