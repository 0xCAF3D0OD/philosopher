/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:58 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/14 23:15:47 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include "printf/ft_printf.h"

// # define INITIAL_STOCK	20
// # define NB_CLIENT		5

typedef struct		s_philosopher
{
	int				id;
	int				x_ate;
	pthread_mutex_t	*left_fork_id;
	pthread_mutex_t	*right_fork_id;
	long long		t_last_meal;
	// struct s_rules	*rules;
	pthread_t		thread_id;
}					t_philosopher;

typedef struct		s_data
{
	int				number_of_philosopher;
	int				fork;
	int				time_to_die;
	int				time_eat;
	int				time_to_sleep;
	int				*table;
	t_philosopher	*philo;
}					t_data;

typedef struct 			s_thread
{
	int					stock;
	pthread_t			*new_thread;
	pthread_mutex_t		*fork_g;
	pthread_mutex_t		*fork_d;
}						t_thread;

// typedef struct 	s_timeval
// {
// 	time_t		diff_sec;
// 	suseconds_t	diff_usec;
// }				t_timeval;

int	ft_atoi(char *nptr);

#endif
