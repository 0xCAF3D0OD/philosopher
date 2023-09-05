/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:47:49 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/08/21 15:20:20 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_the_mutex(pthread_mutex_t *forks, t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->numb_of_philo)
		pthread_mutex_destroy(&forks[i]);
}

void	init_info_philos(pthread_mutex_t *fork,
			t_rules *rules, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < rules->numb_of_philo)
	{
		philos[i].id = i;
		philos[i].t_last_meal = 0;
		philos[i].t_sleep = 0;
		philos[i].x_ate = 0;
		philos[i].is_dead = 0;
		philos[i].rules = rules;
		philos[i].left_fork_id = &fork[i];
		if (rules->numb_of_philo != i + 1)
		{
			philos[i].right_fork_id = &fork[i + 1];
		}
		else
			philos[i].right_fork_id = &fork[0];
	}
}

void	condition_philosophers(t_rules *rules)
{
	t_data			*data;
	t_philos		*philos;
	pthread_t		*ph_thread;
	pthread_mutex_t	*fork;

	data = malloc(sizeof(t_data) * rules->numb_of_philo);
	fork = malloc(sizeof(pthread_mutex_t) * rules->numb_of_philo);
	philos = (t_philos *) malloc(sizeof(t_philos) * rules->numb_of_philo);
	ph_thread = malloc(sizeof(pthread_t) * rules->numb_of_philo);
	timestamp();
	init_info_philos(fork, rules, philos);
	launche_mutex(fork, rules);
	launche_threads(ph_thread, rules, philos);
	destroy_the_mutex(fork, rules);
	free(fork);
	free(philos);
	free(data);
	free(ph_thread);
}

// if (the_prohibited_nbr(av[2]) == 1)
// 	av[2] = "410";
int	condition_rules_args(int ac, char **av, t_rules *rules)
{
	if (check_argv(av) != 0)
		return (1);
	if (ac < 1 || av[1] == NULL)
		return (2);
	rules->numb_of_philo = ft_atoi(av[1]);
	if (ac < 2 || av[2] == NULL)
		return (3);
	rules->time_to_die = ft_atoi(av[2]);
	if (ac < 3 || av[3] == NULL)
		return (4);
	rules->time_eat = ft_atoi(av[3]);
	if (ac < 4 || av[4] == NULL)
		return (5);
	rules->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules->nb_time_to_eat = ft_atoi(av[5]);
	else
		rules->nb_time_to_eat = -1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_rules	*rules;
	int		ret;

	ret = 0;
	rules = (t_rules *) malloc(sizeof(t_rules));
	ret = condition_rules_args(argc, argv, rules);
	if (ret)
		ft_print_error(argc, ret, argv);
	if (!(ret))
		condition_philosophers(rules);
	free(rules);
	return (0);
}
