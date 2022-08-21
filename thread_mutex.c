/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:22:16 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/08/16 20:52:53 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_manager(void *arg)
{
	t_philos	*philos;
	t_rules		*rules;

	philos = (t_philos *) arg;
	rules = philos->rules;
	if (philos->id % 2 == 0)
		usleep(900 * rules->time_eat);
	while (philos->is_dead == 0 && philos->x_ate != rules->nb_time_to_eat)
		ft_routine(philos, rules);
	return (NULL);
}

void	check_if_alright(pthread_t *thread, t_rules *rules, t_philos *philos)
{
	int	i;

	i = 0;
	while (eating_nb(rules, philos) == 0 && philos[0].is_dead == 0)
	{
		i = 0;
		while (i < rules->numb_of_philo)
		{
			if (check_if_dead(rules, &philos[i], i) == 1)
			{
				dead_fct(rules, philos);
				break ;
			}
			i++;
		}
	}
	i = -1;
	while (++i < rules->numb_of_philo)
		pthread_join(thread[i], NULL);
}

void	launche_threads(pthread_t *thread, t_rules *rules, t_philos *philos)
{
	int	i;

	i = -1;
	ft_print(0, 0, 0);
	while (++i < rules->numb_of_philo)
	{
		pthread_create(&thread[i], NULL, thread_manager, &philos[i]);
		usleep(100);
	}
	check_if_alright(thread, rules, philos);
}

void	launche_mutex(pthread_mutex_t *fork, t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->numb_of_philo)
	{
		pthread_mutex_init(&fork[i], NULL);
	}
}
