/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:25:25 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/16 17:10:43 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_thread(t_data *rules)
{
	int	i;

	i = rules->numb_of_philo;
	while(--i >= 0)
	{
		pthread_create()
	}
}

void	init_value_philo(char **av, t_data *rules)
{
	int	i;
	int	result;

	(void) av;
	ft_printf("%d\n", rules->numb_of_philo);
	i = rules->numb_of_philo;
	result = 0;
	while (--i >= 0)
	{
		rules->philo[i].id = i;
		rules->philo[i].x_ate = 0;
		rules->philo[i].left_fork_id = &i;
		result = (i + 1) % rules->numb_of_philo;
		rules->philo[i].right_fork_id = &result;
		// printf("left = %d\n", rules->philo[i].left_fork_id);
		// printf("right = %d\n", rules->philo[i].right_fork_id);
	}
}

int	mutex_init(t_data *rules)
{
	int	i;

	i = -1;
	while (++i <= rules->numb_of_philo)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	return (0);
}

void	init_value_av(char **av, t_data **rules)
{
	*rules = (t_data *) malloc(sizeof(t_data));
	(*rules)->numb_of_philo = ft_atoi(av[1]);
	(*rules)->time_to_die = ft_atoi(av[2]);
	(*rules)->time_eat = ft_atoi(av[3]);
	(*rules)->time_to_sleep = ft_atoi(av[4]);
	(*rules)->philo = (t_philos *) malloc(sizeof(t_philos)
			* (*rules)->numb_of_philo);
	// init_struct(rules);
	// if (!(init_time_rules(*rules) == 0))
	// 	printf("wrong\n");
	if (mutex_init(*rules))
		return 1;
}

int	condition_error(int ac, char **av)
{
	if (ac != 5)
		return (1);
	if (ft_atoi(av[1]) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		*rules;
	t_thread	*thread;

	printf("welcome to the philosopher problem!\n");
	if (condition_error(ac, av))
		return (printf("wrong input = 4 input required && mini 2 philo\n"));
	init_value_av(av, &rules);
	init_value_philo(av, rules);
	init_thread(rules, thread);
	// manage_thread();
	return (0);
}

// static int    init_time(void)
// {
//     struct timeval tv;
//     int    time;

//     gettimeofday(&tv, NULL);
//     time = tv.tv_sec * 1000;
//     time += (tv.tv_usec / 1000);
//     return (time);
// }

// int        ft_time(void)
// {
//     static int    time;

//     if (time == 0)
//         time = init_time();
//     return (init_time() - time);
// }

// int	init_time_rules(t_data *rules)
// {
// 	if (ft_time() > rules->time_eat || ft_time() > rules->time_to_sleep 
// 		|| ft_time() > rules->time_to_die)
// 		return (1);
// 	return (0);
// }