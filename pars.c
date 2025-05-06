/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:28:31 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/06 20:09:19 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int check(t_philo *s, char **av, int ac)
{
    int j;
    int i;

    j = 1;
    s->av = av;
    while(ac > j)
    {
        i = 0;
        while(s->av[j][i])
        {
            if(!ft_isdigit(s->av[j][i]))
                return (error_exit("Error : Non-numeric"), 0);
            i++;
        }
        j++;
    }
    return (1);
}