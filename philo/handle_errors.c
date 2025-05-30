/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:09:40 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/29 19:00:13 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
 
void	free_every_thing(t_philo *p, t_share *s)
{
	int		i;
	int		num;

	num = s->philos;
	i = 0;
	while (i < num)
    {
		pthread_mutex_destroy(&s->forks[i]);
        i++;
    }
	pthread_mutex_destroy(p->share->mtx_died);
	pthread_mutex_destroy(p->share->print);
	free(s->forks);
	free(s->mtx_died);
	free(s->print);
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
		return(0);
	}
	return (a);
}

void error_exit(char *error)
{
	printf("%s\n", error);
	return ;
}
