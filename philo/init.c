/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:10:10 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/12 16:15:19 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    data_init(t_philo *p)
{
    int i;

    i = 0;
    printf("%d\n\n", p->share->philos);
    p->share->forks = ft_malloc(sizeof(pthread_mutex_t) * p->share->philos);
    while (i < p->share->philos)
    {
        pthread_mutex_init(&p->share->forks[i], NULL);
        p[i].share = p->share;
        p[i].left_fork = i;
		p[i].right_fork = (i + 1) % p->share->philos;
        i++;
    }
}