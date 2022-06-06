/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:58 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/03 23:12:45 by dino             ###   ########.fr       */
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

typedef struct s_rules t_rules;

typedef struct		s_philos
{
	int				id;
	int				x_ate;
	int				is_dead;
	long long		t_last_meal;
	pthread_mutex_t	*left_fork_id;
	pthread_mutex_t	*right_fork_id;
	pthread_t		thread_id;
	t_rules			*rules;
}					t_philos;

struct		s_rules
{
	int				numb_of_philo;
	int				time_to_die;
	int				time_eat;
	int				time_to_sleep;
	int				nb_time_to_eat;

};

typedef	struct		s_data
{
	pthread_mutex_t	*forks;
	t_philos		*philos;
	t_rules			*rules;
}					t_data;

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
void	condition_rules_args(int ac, char **av, t_rules *rules);
void	condition_philosophers(t_data *data, t_rules *rules);
void	init_info_philos(t_data *data, t_rules *rules, t_philos *philos);
void	mutex_and_threads_function(t_data *data, t_rules *rules, t_philos *philos);

/*	time_philo	*/

// static long long	init_timestamp(void);
long long			timestamp(void);

/*	print_philos	*/

void	ft_print(int ret, int i);

/*	thread_mutex	*/

void	*thread_manager(void *arg);
void	lauche_threads(t_data *data, t_rules *rules, t_philos *philos);
void	lauche_mutex(t_data *data, t_rules *rules, t_philos *philos);

/* check_fcts	*/

int		check_if_dead(t_rules *rules, t_philos *philos, int i);
void	dead_fct(t_rules *rules, t_philos *philos);
int		eating_nb(t_rules *rules, t_philos *philos);
void	free_philos(t_philos *philos);

#endif

