/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:09:40 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/14 13:54:16 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
 
void free_all(t_philo *p)
{
	int i;
	
	i = 0;
	if (!p || !p->share)
        return ;
	
}

void	*safe_malloc(size_t size)
{
	void	*a;

	a = malloc(size);
	if (a == NULL)
	{
		error_exit("Error: malloc failed\n");
		return(0);
	}
	return (a);
}

void error_exit(char *error)
{
	printf("%s\n", error);
	return ;
}
