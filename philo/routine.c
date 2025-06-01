/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:21:12 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/30 17:47:38 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *s, char *msg)
{
	pthread_mutex_lock(&s->share->print);
	printf("%lld philo number %d %s\n",
		get_time() - s->share->starting_time, s->id, msg);
	pthread_mutex_unlock(&s->share->print);
}

int	check_death(t_philo *s)
{
	int	d;

	pthread_mutex_lock(&s->share->mtx_died);
	d = s->share->died;
	pthread_mutex_unlock(&s->share->mtx_died);
	return (d);
}

void	think(t_philo *s)
{
	if (!check_death(s))
		print_action(s, "is thinking");
}

int	take_forks(t_philo *s)
{
	if (s->id % 2 == 0)
	{
		pthread_mutex_lock(&s->share->forks[s->right_fork]);
		pthread_mutex_lock(&s->share->forks[s->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&s->share->forks[s->left_fork]);
		pthread_mutex_lock(&s->share->forks[s->right_fork]);
	}
	if (check_death(s))
	{
		drop_forks(s);
		return (0);
	}
	print_action(s, "has taken a fork");
	print_action(s, "has taken a fork");
	return (1);
}

int	eat(t_philo *s, int *meals)
{
	print_action(s, "is eating");
	sleeper(s->share->time_to_eat);
	pthread_mutex_lock(&s->share->meal_mtx);
	(*meals)--;
	s->last_meal = get_time();
	pthread_mutex_unlock(&s->share->meal_mtx);
	if (check_death(s))
	{
		drop_forks(s);
		return (0);
	}
	return (1);
}

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
