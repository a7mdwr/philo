/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:28:31 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/12 11:48:21 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int check(char **av, int ac)
{
    int j;
    int i;

    j = 1;
    if (ac != 5 && ac != 6)
        return(error_exit("Error: wrong number of arguments"), 0);
    while(ac > j)
    {
        i = 0;
        while(av[j][i])
        {
            if(!ft_isdigit(av[j][i]))
                return (error_exit("Error : Non-numeric"), 0);
            i++;
        }
        j++;
    }
    return (1);
}

int    parsing(t_share *s, char **av)
{
    s->philos = ft_atoi(av[1]) * 1000;
    s->time_to_die = ft_atoi(av[2]) * 1000;
    s->time_to_eat = ft_atoi(av[3]) * 1000;
    s->time_to_sleep = ft_atoi(av[4]) * 1000;
    if (!s->philos || !s->time_to_die || !s->time_to_eat|| !s->time_to_sleep)
        return (error_exit("Error: Values must be > 0"), 0);
    if (av[5])
    {
        s->must_eat = ft_atoi(av[5]) * 1000;
        if (s->must_eat <= 0)
            return (error_exit("Error: (must_eat) must be > 0"), 0);
    }
    else
        s->must_eat = -1;
    data_init(&s);
    return (1);
}
