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
 
void free_all(t_philo *p)
{
    int i;

    if (!p || !p->share)
        return;
    pthread_mutex_destroy(&p->share->print);
    pthread_mutex_destroy(&p->share->mtx_died);
    if (p->share->meal_mtx)
    {
        pthread_mutex_destroy(p->share->meal_mtx);
        free(p->share->meal_mtx);
        p->share->meal_mtx = NULL;
    }
    if (p->share->forks)
    {
        i = 0;
        while (i < p->share->philos)
        {
            pthread_mutex_destroy(&p->share->forks[i]);
            i++;
        }
        free(p->share->forks);
        p->share->forks = NULL;
    }
    free(p->share);
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
