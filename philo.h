/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:58 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/06 16:04:54 by kdi-noce         ###   ########.fr       */
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
	long long		t_sleep;
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
	t_philos		*philos;
	t_rules			*rules;
}					t_data;

int	ft_atoi(char *nptr);

/*	philosopher_main	*/

int		condition_erreur(int ac);
void	condition_rules_args(int ac, char **av, t_rules *rules);
void	condition_philosophers(t_data *data, t_rules *rules);
void	init_info_philos(pthread_mutex_t *fork, t_rules *rules, t_philos *philos);
void	mutex_and_threads_function(pthread_t *philo, t_data *data, t_rules *rules, t_philos *philos);

/*	time_philo	*/

// static long long	init_timestamp(void);
long long			timestamp(void);

/*	print_philos	*/

void	ft_print(int ret, int i, long long time);

/*	thread_mutex	*/

void	*thread_manager(void *arg);
void	check_if_alright(pthread_t *thread, t_rules *rules, t_philos *philos);
void	launche_threads(pthread_t *thread, t_rules *rules, t_philos *philos);
void	launche_mutex(pthread_mutex_t *fork, t_rules *rules);

/*	ft_routine	*/

void	ft_routine(t_philos *philos, t_rules *rules);
void	ft_take_forks(t_philos *philos, t_rules *rules);
void	ft_eat(t_philos *philos, t_rules *rules);
void	ft_is_sleeping(t_philos *philos);
void	ft_put_forks(t_philos *philos);

/* check_fcts	*/

int		check_if_dead(t_rules *rules, t_philos *philos, int i);
void	dead_fct(t_rules *rules, t_philos *philos);
int		eating_nb(t_rules *rules, t_philos *philos);
void	free_philos(t_philos *philos);

#endif

