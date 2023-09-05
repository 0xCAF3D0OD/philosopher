/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:33:17 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/08/20 15:53:06 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_put_forks(t_philos *philos)
{
	pthread_mutex_unlock(philos->right_fork_id);
	if (philos->is_dead == 0)
		ft_print(5, philos->id, timestamp());
	pthread_mutex_unlock(philos->left_fork_id);
	if (philos->is_dead == 0)
		ft_print(6, philos->id, timestamp());
}

void	ft_sleeping(t_philos *philos)
{
	if (philos->is_dead == 0)
		ft_print(9, philos->id, timestamp());
	usleep(990 * philos->rules->time_to_sleep);
	if (philos->is_dead == 0)
		ft_print(THINK_MSG, philos->id, timestamp());
}

void	ft_eat(t_philos *philo, t_rules *rules)
{
	if (philo->is_dead == 0)
		ft_print(7, philo->id, timestamp());
	philo->x_ate++;
	philo->t_last_meal = timestamp();
	if (rules->numb_of_philo != 1)
		usleep(990 * philo->rules->time_eat);
}

void	ft_take_forks(t_philos *philos)
{
	pthread_mutex_lock(philos->right_fork_id);
	if (philos->is_dead == 0)
		ft_print(4, philos->id, timestamp());
	pthread_mutex_lock(philos->left_fork_id);
	if (philos->is_dead == 0)
		ft_print(3, philos->id, timestamp());
}

void	ft_routine(t_philos *philos, t_rules *rules)
{
	ft_take_forks(philos);
	ft_eat(philos, rules);
	ft_put_forks(philos);
	ft_sleeping(philos);
}
