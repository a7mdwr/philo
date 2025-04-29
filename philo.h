/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:22:59 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/29 09:07:55 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo
{
    char **array;
} t_philo;

# define TAB '\t'
# define BACKSPACE '\b'
# define CARRIAGE '\r'
# define SPACE ' '
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int check(t_philo *s);

#endif