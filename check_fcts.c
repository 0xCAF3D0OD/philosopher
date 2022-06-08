/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:24:55 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/08 17:59:44 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_rules *rules, t_philos *philos, int i)
{
	static int	dead;
	long long	ret;

	if (dead == 0)
	{
		if ((ret = timestamp() - philos->t_last_meal) > rules->time_to_die)
		{
			dead = 1;
			pthread_mutex_unlock(philos->left_fork_id);
			pthread_mutex_unlock(philos->right_fork_id);
			ft_print(8, i, ret, 0);
		}
	}
	return (dead);
} 

void	dead_fct(t_rules *rules, t_philos *philos)
{
	int	i;

	i = -1;
	philos->is_dead = 1;
	while (++i != rules->numb_of_philo)
	{
		philos[i].is_dead = 1;
		pthread_mutex_unlock(philos[i].left_fork_id);
		pthread_mutex_unlock(philos[i].right_fork_id);
	}
}

int	eating_nb(t_rules *rules, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < rules->numb_of_philo)
	{
		if (philos[i].x_ate != rules->nb_time_to_eat)
			return (0);
	}
	return (1);
}