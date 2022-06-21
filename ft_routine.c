/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:33:17 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/21 18:07:49 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_put_forks(t_philos *philos)
{
	pthread_mutex_unlock(philos->right_fork_id);
	ft_print(5, philos->id, 0);
	pthread_mutex_unlock(philos->left_fork_id);
	ft_print(6, philos->id, 0);
}

void	ft_sleeping(t_philos *philos)
{
		ft_print(9, philos->id, timestamp());
		usleep(1000 * philos->rules->time_to_sleep);
		ft_print(10, philos->id, timestamp());
}

void	ft_eat(t_philos *philos, t_rules *rules)
{
	int			time;
	long long	ret;
	// (void)	rules;

	ret = 0;
	time = timestamp();
		if (rules->nb_time_to_eat == -1)
			ft_print(7, philos->id, ret);
		ret = time - timestamp();
		ft_print(7, philos->id, ret);
		philos->x_ate++;
		philos->t_last_meal = timestamp();
	ft_put_forks(philos);
}

void	ft_take_forks(t_philos *philos, t_rules *rules)
{
	static int	i;

	i = 0;

	printf("%p\n%p\n", philos->right_fork_id, philos->left_fork_id);
	pthread_mutex_lock(philos->right_fork_id);
	ft_print(4, philos->id, timestamp());
	pthread_mutex_lock(philos->left_fork_id);
	ft_print(3, philos->id, timestamp());
	if (rules->numb_of_philo == 1)
		usleep(1000 * philos->rules->time_eat);
}

void	ft_routine(t_philos *philos, t_rules *rules)
{
		ft_take_forks(philos, rules);
		ft_eat(philos, rules);
		ft_sleeping(philos);
}

void	*thread_manager(void *arg)
{
	t_philos	*philos;
	t_rules		*rules;

	philos = (t_philos *) arg;
	rules = philos->rules;
	if (rules->numb_of_philo % 2 == 0)
		usleep(900 * rules->time_eat);
	while (philos->is_dead == 0 && philos->x_ate != rules->nb_time_to_eat)
			ft_routine(philos, rules);
	return (NULL);
}
