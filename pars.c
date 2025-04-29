/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:28:31 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/29 10:00:37 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int check(t_philo *s, char **av, int ac)
{
    int j;
    int i;
    int first;

    first = 1;
    j = 1;
    s->array = av;
    while(ac > j)
    {
        i = 0;
        while(s->array[j][i])
        {
            if(!ft_isdigit(s->array[j][i]))
                return (perror("Error : there is char in args"), 0);
            i++;
        }
        if (first)
            s->philos = ft_atoi(s->array[j]);
        j++;
        ft_atoi(s->array[j]);
        first  = 0;
    }
    return (1);
}