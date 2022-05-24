/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:22:16 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/24 19:03:15 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_is_sleeping(t_data *rules)
{
	(void) rules;
	printf("is_sleeping\n");
}

void	philos_is_eating(t_data	*rules, int i)
{
	(void)rules;
	printf("3\n");
	printf("4\n");
	pthread_mutex_lock(rules->philos->left_fork_id);
	ft_print(3, i);
	printf("4\n");
	pthread_mutex_lock(rules->philos->right_fork_id);
	ft_print(4, i);
	ft_print(7, i);
	printf("4\n");
	pthread_mutex_unlock(rules->philos->right_fork_id);
	ft_print(6, i);
	printf("4\n");
	pthread_mutex_unlock(rules->philos->left_fork_id);
	ft_print(5, i);
	printf("4\n");
}

void	*thread_manager(void *arg)
{
	t_data		*rules;
	// int			i;

	rules = (t_data*) arg;
	printf("1\n");
	if ((rules->numb_of_philo % 2) == 0)
		usleep(100);
	while ((rules->philos->is_dead) == 0)
	{
		printf("2\n");
		philos_is_eating(rules, rules->philos->id);
		philos_is_sleeping(rules);
	}
	return (NULL);
}

void	lauche_threads(t_data *rules)
{
	int			i;

	i = -1;
	while (++i < rules->numb_of_philo)
	{
		pthread_create(&(rules->philos[i].thread_id), NULL, thread_manager, &rules->philos[i]);
	}
	check_if_dead(rules);
}

void	lauche_mutex(t_data *rules)
{
	int	i;

	i = -1;
	//printf("ID -> %d\n", rules->philos[1].id);
	while (++i < rules->numb_of_philo)
	{
		pthread_mutex_init(&(rules->forks[i]), NULL);
	}
	//printf("ID -> %d\n", rules->philos[1].id);
}