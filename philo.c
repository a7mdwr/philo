/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:21:25 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/08 13:40:15 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"


int main(int ac, char **av)
{
    t_philo s;
    t_share p;
    pthread_t *threads;
    int i;

    i = 0;
    ft_bzero(&s, sizeof(t_philo));
    if(!check(av, ac) || !parsing(&p, av))
        return(0);
    
}