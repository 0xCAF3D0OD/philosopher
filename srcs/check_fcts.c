/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:24:55 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/08/16 22:14:28 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_rules *rules, t_philos *philo, int i)
{
	static int	dead;
	long long	ret;
	long long	now;

	if (dead == 0)
	{
		now = timestamp();
		ret = now - philo->t_last_meal;
		if (ret > rules->time_to_die)
		{
			dead = 1;
			ft_print(8, i, ret);
			pthread_mutex_unlock(philo->left_fork_id);
			pthread_mutex_unlock(philo->right_fork_id);
		}
	}
	return (dead);
}

void	dead_fct(t_rules *rules, t_philos *philos)
{
	int	i;

	i = -1;
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

int	check_argv(char **argv)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (argv[i] != NULL && ret != 1)
	{
		ret = chek_digit(argv[i]);
		if (ret == 0)
			ret = chek_long(argv[i]);
		i++;
	}
	return (ret);
}
