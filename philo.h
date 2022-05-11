/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:58 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/11 11:57:42 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

# define INITIAL_STOCK	20
# define NB_CLIENT		5

typedef struct	s_data
{
	int			number_of_philosopher;
	int			fork;
	int			time_to_di;
	int			time_eat;
	int			time_to_sleep;
	int			*table;
}				t_data;

typedef struct 			s_thread
{
	int					stock;
	pthread_t			new_thread;
	pthread_mutex_t		fork_g;
	pthread_mutex_t		fork_d;
}						t_thread;

typedef struct 	s_timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}				t_timeval;

int	ft_atoi(char *nptr);

#endif
