/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:07:14 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/12 12:29:14 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eaing_samultion
{
    
}

void start_eat(t_share *s)
{
    int i;

    i = 0;
    if (s->must_eat == 0)
        return ;
    // else if (s->must_eat == 1)
    else
    {
        while (s->philos > i)
        {
            pthread_create(&s->philos[i], eating_samultion, )
            i++;
        }
    }
    
}