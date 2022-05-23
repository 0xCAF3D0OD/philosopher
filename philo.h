/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:58 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/23 14:06:04 by kdi-noce         ###   ########.fr       */
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

typedef struct s_data t_data;

typedef struct		s_philos
{
	int				id;
	int				x_ate;
	int				first_time;
	pthread_mutex_t	*left_fork_id;
	pthread_mutex_t	*right_fork_id;
	long long		t_last_meal;
	t_data			*rules;
	pthread_t		thread_id;
}					t_philos;

struct		s_data
{
	int				numb_of_philo;
	int				time_to_die;
	int				time_eat;
	int				time_to_sleep;
	int				begining;
	int				is_dead;
	t_philos		*philo;
	pthread_mutex_t	*forks;
};

typedef struct 			s_thread
{
	int					stock;
	pthread_t			*new_thread;
	pthread_mutex_t		*fork_g;
	pthread_mutex_t		*fork_d;
}						t_thread;

int	ft_atoi(char *nptr);

#endif
