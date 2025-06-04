/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:09:40 by aradwan           #+#    #+#             */
/*   Updated: 2025/06/04 13:54:07 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *p)
{
	int		i;
	t_share	*s;

	s = p->share;
	if (!p || !s)
		return ;
	pthread_mutex_destroy(&s->print);
	pthread_mutex_destroy(&s->meal_mtx);
	pthread_mutex_destroy(&s->mtx_died);
	if (s->forks)
	{
		i = 0;
		while (i < s->philos)
		{
			pthread_mutex_destroy(&s->forks[i]);
			i++;
		}
		free(s->forks);
	}
	free(s);
	free(p);
}

void	*safe_malloc(size_t size)
{
	void	*a;

	a = malloc(size);
	if (a == NULL)
	{
		error_exit("Error: malloc failed\n");
		return (0);
	}
	return (a);
}

void	error_exit(char *error)
{
	printf("%s\n", error);
	return ;
}
