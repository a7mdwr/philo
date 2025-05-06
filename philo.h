/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:22:59 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/06 20:42:36 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# define TAB '\t'
# define BACKSPACE '\b'
# define CARRIAGE '\r'
# define SPACE ' '
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h> 
#include <stdbool.h>

typedef pthread_mutex_t t_mtx;

typedef enum e_mutexx
{
    LOCK,
    UNLOCK,
    INIT,
    DESTOY,
    CREAT,
    JOIN,
    DETACH,
}   t_mutex;

typedef struct s_share
{
    t_mtx *left_fork;
    t_mtx *right_fork;
    t_mtx *forks;
    int philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
    int simulation;
}t_share;

// ./philo 5 800 200 200

typedef struct s_philo
{
    int id;
    int died;
    t_share *shared;
} t_philo;


int 	ft_atoi(const char *str);
int 	ft_isdigit(int c);
int     check(t_philo *s, char **av, int ac);
void	ft_bzero(void *s, size_t n);
void    *routine(void *arg);
void	*ft_malloc(size_t size);
void    error_exit(char *error);

#endif