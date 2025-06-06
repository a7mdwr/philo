/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:21:25 by aradwan           #+#    #+#             */
/*   Updated: 2025/06/04 13:55:16 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = NULL;
	if (ac != 5 && ac != 6)
		return (error_exit("Error: wrong number of arguments"), 0);
	if (!check(av, ac) || !parsing(av))
		return (0);
	p = philo(p, av);
	data_init(p);
	start_simulation(p);
	while (1)
	{
		if (!check_for_die(p))
		{
			while (i < p->share->philos)
			{
				pthread_join(p[i].thread_id, NULL);
				i++;
			}
			return (free_all(p), 0);
		}
	}
	return (free_all(p), 0);
}
