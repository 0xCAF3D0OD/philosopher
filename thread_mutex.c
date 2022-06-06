/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:22:16 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/06 02:34:23 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_is_sleeping(t_rules *rules, t_philos *philos, int i)
{
	(void) philos;
	(void) rules;
	// ft_print(3, i);
}

// void	philos_is_eating(t_data	*rules, t_philos *philos, int i)
// {
// 	int	time;

// 	time = timestamp();
// 	if (philos->is_dead == 0)
// 	{
// 		if (rules->nb_time_to_eat == -1)
// 			ft_print(9, i);
// 		else
// 		{
// 			philos->x_ate++;
// 			ft_print(4, i);
// 		}
// 		philos->t_last_meal = timestamp();
// 		while (timestamp() - time < rules->time_eat && philos->is_dead == 0)
// 			usleep(100);
// 	}
// 	pthread_mutex_unlock(philos->left_fork_id);
// 	ft_print(5, i);
// 	pthread_mutex_unlock(philos->right_fork_id);
// 	ft_print(6, i);
// }

void	philos_is_eating(t_philos *philos, int i)
{
	int	time;
	t_rules	*rules;

	time = timestamp();
	rules = philos->rules;
	if (rules->numb_of_philo % 2 == 0)
		usleep(100);
	pthread_mutex_lock(philos->left_fork_id);
	ft_print(3, i);
	pthread_mutex_lock(philos->right_fork_id);
	ft_print(4, i);
	if (philos->is_dead == 0)
	{
		ft_print(7, i);
		philos->x_ate++;
		philos->t_last_meal = timestamp();
		usleep(rules->time_eat);
		// while (tcle < rules->time_eat)
		// 	usleep(100);
	}
	pthread_mutex_unlock(philos->left_fork_id);
	pthread_mutex_unlock(philos->right_fork_id);
}

void	*thread_manager(void *arg)
{
	t_rules		*rules;
	t_philos	*philos;
	int			idx;

	philos = (t_philos*) arg;
	rules = philos->rules;
	idx = philos->id;
	while (philos->is_dead == 0 && philos->x_ate != rules->nb_time_to_eat)
	{
		if (philos->is_dead == 0)
		{
			philos->x_ate++;
			// philos_is_eating(philos, idx);
		}
		if (philos->is_dead == 0)
		{
			philos_is_sleeping(rules, philos, philos->id);
		}
	}
	return (NULL);
}

void check_if_alright(t_rules *rules, t_philos *philos)
{
	int i;

	i = 0;
	printf("3.6.2.2.1\n");
	while (eating_nb(rules, philos) == 0 && philos[0].is_dead == 0)
	{
		//printf("3.6.2.2.2\n");
		i = 0;
		while(i < rules->numb_of_philo)
		{
			if (check_if_dead(rules, &philos[i], i) == 1)
			{
				dead_fct(rules, philos);
				break ;
			}
			i++;
		}
	}
	printf("3.6.2.2.4\n");
	i = 0;
	while (i < rules->numb_of_philo)
	{
		printf("in");
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
	free_philos(philos);
	printf("3.6.2.2.5\n");
}

void	lauche_threads(t_data *data, t_rules *rules, t_philos *philos)
{
	int	i;

	i = -1;
	printf("3.6.2.1\n");
	while (++i < rules->numb_of_philo)
	{
		pthread_create(&(philos[i].thread_id), NULL, thread_manager, &philos[i]);
	}
	printf("3.6.2.2\n");
	check_if_alright(rules, philos);
	printf("3.6.2.3\n");
}

void	lauche_mutex(t_data *data, t_rules *rules, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < rules->numb_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
	}
}
