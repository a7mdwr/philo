/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:22:59 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/09 15:01:27 by aradwan          ###   ########.fr       */
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
# include <stdbool.h>
# include <errno.h>

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
    int philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
    int simulation;
    bool    end_simulationœ;
    t_philo *philo;
    t_fork  *forks;
}t_share;

typedef struct s_fork
{
    t_mtx fork;
    int   fork_id;
}   t_fork;

typedef struct s_philo
{
    int id;
    int meals_count;
    bool full;
    t_fork *left_fork;
    t_fork *right_fork;
    t_share *share;
} t_philo;


int 	ft_atoi(const char *str);
int 	ft_isdigit(int c);
int     check(char **av, int ac);
void	ft_bzero(void *s, size_t n);
void    *routine(void *arg);
void	*ft_malloc(size_t size);
void    error_exit(char *error);
int     parsing(t_share *s, char **av);
void	safe_mutex(t_mtx *mutex, t_mutex opcode);
void handle_mutex_error(int status, t_mutex opcode);

#endif