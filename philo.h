/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:58 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/24 17:01:04 by kdi-noce         ###   ########.fr       */
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


// pointeur char *ptr;
//			ptr = "salut";

typedef struct s_data t_data;

typedef struct		s_philos
{
	int				id;
	int				x_ate;
	int				first_time;
	int				is_dead;
	long long		t_last_meal;
	pthread_mutex_t	*left_fork_id;
	pthread_mutex_t	*right_fork_id;
	pthread_t		thread_id;
	t_data			*rules;
}					t_philos;

struct		s_data
{
	int				numb_of_philo;
	int				time_to_die;
	int				time_eat;
	int				time_to_sleep;
	pthread_mutex_t	*forks;
	t_philos		*philos;
};

typedef struct 			s_thread
{
	int					stock;
	pthread_t			*new_thread;
	pthread_mutex_t		*fork_g;
	pthread_mutex_t		*fork_d;
}						t_thread;

int	ft_atoi(char *nptr);

/*	philosopher_main	*/

int		condition_erreur(int ac);
void	condition_philosophers(char **av, t_data *rules);
void	init_info_philos(t_data *rules);
void	mutex_and_threads_function(t_data *rules);

/*	time_philo	*/

// static long long	init_timestamp(void);
long long			timestamp(void);

/*	print_philos	*/

void	ft_print(int ret, int i);

/*	thread_mutex	*/

void	*thread_manager(void *arg);
void	lauche_threads(t_data *rules);
void	lauche_mutex(t_data *rules);

/* check_fcts	*/

long long	check_if_dead(t_data *rules);

#endif
