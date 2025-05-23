/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:28:31 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/15 13:23:05 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int check(char **av, int ac)
{
    int j;
    int i;

    j = 1;
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

int    parsing(t_philo *p, char **av)
{
    int must_eat;

    must_eat = 0;
    if (!av[1] || !av[2] || !av[3]|| !av[4])
        return (error_exit("Error: Values must be > 0"), 0);
    if (av[5])
    {
        must_eat = ft_atoi(av[5]) * 1000;
        if (must_eat <= 0)
            return (error_exit("Error: (must_eat) must be > 0"), 0);
    }
    else
        p->share->must_eat = -1;
    return (1);
}
