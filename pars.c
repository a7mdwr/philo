/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:28:31 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/29 09:05:44 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int check(t_philo *s)
{
    int j;
    int i;
    
    i = 0;
    j = 0;
    while(s->array[j])
    {
        if(!ft_isdigit(s->array[j][i]))
            return (perror("Error : there is char in args"), 0);
        ft_atoi(s->array[j]);
        i++;
        j++;
    }
    return (1);
}