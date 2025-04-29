/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:28:31 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/29 09:33:15 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int check(t_philo *s, char **av, int ac)
{
    int j;
    int i;
    
    i = 0;
    j = 1;
    s->array = av;
    while(ac > j)
    {
        while(s->array[j][i])
        {
            if(!ft_isdigit(s->array[j][i]))
                return (perror("Error : there is char in args"), 0);
            i++;
        }
        ft_atoi(s->array[j]);
        j++;
    }
    return (1);
}