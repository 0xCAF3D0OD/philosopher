/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:24:55 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/26 20:18:02 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_data *rules)
{
	static int	dead;

	if (dead == 0)
	{
		if (timestamp() - rules->philos->t_last_meal > rules->time_to_die)
		{
			rules->philos->is_dead = 1;
		}
	}
	return (dead);
}

void	dead_fct(t_data *rules)
{
	int	i;

	i = -1;
	rules->philos->is_dead = 1;
	while (++i != rules->numb_of_philo)
	{
		rules->philos[i].is_dead = 1;
		pthread_mutex_unlock(rules->philos[i].left_fork_id);
		pthread_mutex_unlock(rules->philos[i].right_fork_id);
	}
}

int	eating_nb(t_data *rules)
{
	int	i;

	i = 0;
	while (i < rules->numb_of_philo)
	{
		if (rules->philos[i].x_ate != rules->nb_time_to_eat)
			return (0);
	}
	return (1);
}