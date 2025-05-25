/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:21:25 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/25 16:38:32 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int main(int ac, char **av)
{
    t_philo *p;
    int i;

    i = 0;
    p = NULL;
    if (ac != 5 && ac != 6)
        return(error_exit("Error: wrong number of arguments"), 0);
    if(!check(av, ac))
        return(0);
    p = philo(p, av);
    data_init(p);
    start_simulation(p);
    while (1)
    {
        if(!check_for_die(p))
        {
            while (i < p->share->philos)
            {
                pthread_join(p[i].thread_id, NULL);
                i++;
            }
            return 0;
        }
    }
    return (0);
}