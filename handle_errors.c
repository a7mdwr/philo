/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:09:40 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/09 14:12:25 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void handle_mutex_error(int status, t_mutex opcode)
{
    if (status == 0)
        return ;
    if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK|| opcode == DESTOY))
        error_exit("The value specified by mutex is invalid");
    else if (status == EINVAL && opcode == INIT)
        error_exit("The value specified by attr is invalid");
    else if (status == EDEADLK)
        error_exit("A deadlock would occur if the thread blocked waiting for mutex");
    else if (status == EPERM)
        error_exit("The current thread does not hold a lock on mutex");
    else if (status == ENOMEM)
        error_exit("The process cannot allocate enough memory to createanother mutex");
    else if (status == EBUSY)
        error_exit("Mutex is locked");
}

void	safe_mutex(t_mtx *mutex, t_mutex opcode)
{
    if (opcode == LOCK)
        handle_mutex_error(pthread_mutex_lock(mutex), opcode);
    else if (opcode == UNLOCK)
        handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
    else if (opcode == INIT)
        handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
    else if (opcode == DESTOY)
        handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
    else
        error_exit("Wrong opcode for mutex handle");	
}

void	*ft_malloc(size_t size)
{
	void	*a;

	a = malloc(size);
	if (a == NULL)
	{
		error_exit("Error: malloc failed\n");
		return() 0);
	}
	return (a);
}

void error_exit(char *error)
{
	printf("%s\n", error);
	return ;
}
