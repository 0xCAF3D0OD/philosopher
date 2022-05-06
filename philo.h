/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:58 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/06 17:32:24 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

# define INITIAL_STOCK	20
# define NB_CLIENT		5

typedef struct	s_data
{
	int			nb_philo;
	int			nb_fork;
	int			time_die;
	int			time_eat;
	int			time_sleep;
}				t_data;

typedef struct 			s_thread
{
	int					stock;
	pthread_t			new_thread;
	pthread_mutex_t		lock;
}						t_thread;

// typedef struct 	s_timeval
// {
// 	time_t		tv_sec;
// 	suseconds_t	tv_usec;
// }				t_timeval;

#endif