/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:33:17 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/08 17:14:28 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_put_forks(t_philos *philos)
{
	int			time;
	long long	ret;

	time = timestamp();
	ret = timestamp() - time;
	pthread_mutex_unlock(philos->right_fork_id);
	ft_print(5, philos->id, ret, 0);
	ret = timestamp() - time;
	pthread_mutex_unlock(philos->left_fork_id);
	ft_print(6, philos->id, ret, 0);
}

void	ft_sleeping(t_philos *philos)
{
	int			time;
	long long	ret;

	time = timestamp();
	ret = timestamp() - time;
	if (philos->is_dead == 0)
	{
		ft_print(9, philos->id, ret, 0);
		while(timestamp() - time < philos->rules->time_to_sleep && philos->is_dead == 0)
			usleep(100);
		ft_print(10, philos->id, ret, 0);
	}
}

void	ft_eat(t_philos *philos, t_rules *rules)
{
	int			time;
	long long	ret;

	ret = 0;
	time = timestamp();
	if (philos->is_dead == 0)
	{
		ret = timestamp() - time;
		if (rules->nb_time_to_eat == -1)
			ft_print(7, philos->id, ret, 0);
		else
		{	
			philos->timer++;
			ft_print(7, philos->id, ret, philos->timer);
		}
		philos->x_ate++;
		philos->t_last_meal = timestamp();
		while(timestamp() - time < philos->rules->time_eat && philos->is_dead == 0)
			usleep(100);
	}
	ft_put_forks(philos);
}

void	ft_take_forks(t_philos *philos, t_rules *rules)
{
	int			time;
	long long	ret;
	static int	i;

	time = timestamp();
	i = 0;
	if (rules->numb_of_philo % 2 == 0 && i == 0)
		usleep(100), i++;
	if (timestamp() - time < rules->time_to_die && philos->is_dead == 0)
	{
		pthread_mutex_lock(philos->right_fork_id);
		ret = timestamp() - time;
		ft_print(4, philos->id, ret, 0);
		if (rules->numb_of_philo == 1)
		{
			while(timestamp() - time < rules->time_to_die && philos->is_dead == 0)
				usleep(100);
		}
		pthread_mutex_lock(philos->left_fork_id);
		ret = timestamp() - time;
		ft_print(3, philos->id, ret, 0);
	}
}

void	ft_routine(t_philos *philos, t_rules *rules)
{
	if (philos->is_dead == 0)
		ft_take_forks(philos, rules);
	if (philos->is_dead == 0)
		ft_eat(philos, rules);
	if (philos->is_dead == 0)
		ft_sleeping(philos);
}

void	*thread_manager(void *arg)
{
	t_philos	*philos;
	t_rules		*rules;

	philos = (t_philos *) arg;
	rules = philos->rules;
	while (philos->is_dead == 0 && philos->x_ate != rules->nb_time_to_eat)
	{
		if (philos->is_dead == 0)
			ft_routine(philos, rules);
	}
	return (NULL);
}
