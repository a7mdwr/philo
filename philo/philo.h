/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:22:59 by aradwan           #+#    #+#             */
/*   Updated: 2025/05/14 20:19:10 by aradwan          ###   ########.fr       */
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

typedef struct s_share
{
    int         philos;
    int         time_to_die;
    int         time_to_eat;
    int         time_to_sleep;
    int         must_eat;
    int         sim_stop;
    t_mtx       stop_mtx;
    long long   start_time;
    t_mtx *forks;
}t_share;

typedef struct s_philo
{
    int id;
    int meals_count;
    long long starting_time;
    bool full;
    int left_fork;
    int right_fork;
    long long start_eating;
    int died;
    long long   last_meal;
    t_mtx   meal_mtx;
    pthread_t thread_id;
    t_share *share;
} t_philo;



int 	ft_atoi(const char *str);
int 	ft_isdigit(int c);
int     check(char **av, int ac);
void	ft_bzero(void *s, size_t n);
void    *routine(void *arg);
void	*safe_malloc(size_t size);
void    error_exit(char *error);
void    start_simulation(t_philo *p);
int     parsing(t_philo *p, char **av);
t_philo *philo(t_philo *p, char **av);
// void	safe_mutex(t_mtx *mutex, t_mutex opcode);
// void handle_mutex_error(int status, t_mutex opcode);
void    data_init(t_philo *p);
long long   get_time(void);
#endif