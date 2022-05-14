/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:25:25 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/14 17:34:21 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_value_philo(char **av, t_data *rules)
{
	(void) av;
	ft_printf("%d\n", rules->number_of_philosopher);
	int	i;

	i = -1;
	while (++i < rules->number_of_philosopher)
	{
		ft_printf("%d\n", i);
		// rules[i].left_fork_id = i;
		rules->philo[i].left_fork_id = (i + 1) % rules->number_of_philosopher;
		pthread_mutex_init(&rules->philo[i].left_fork_id, NULL);
		printf("right = %d\n", rules->philo[i].left_fork_id);
	}
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

void	init_struct(t_data **rules)
{
	int	len;

	(*rules)->philo = (t_philosopher *) malloc(sizeof(t_philosopher) * (*rules)->number_of_philosopher);
	len = (*rules)->number_of_philosopher;
	(*rules)->table = NULL;
	(*rules)->table = malloc(sizeof(int*) * (len + 1));
	(*rules)->table[len + 1] = 0;
}

void	init_value_av(char **av, t_data **rules)
{
	*rules = (t_data*) malloc(sizeof(t_data));
	(*rules)->number_of_philosopher = ft_atoi(av[1]);
	(*rules)->time_to_die = ft_atoi(av[2]);
	(*rules)->time_eat = ft_atoi(av[3]);
	(*rules)->time_to_sleep = ft_atoi(av[4]);
	init_struct(rules);
	// if (!(init_time_rules(*rules) == 0))
	// 	printf("wrong\n");
}
int	condition_error(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 2)
		return (1);
	if (ft_atoi(av[1]) == 1)
		return (1);
	return (0);
}
int	main(int ac, char **av)
{
	t_data	*rules;

	printf("welcome to the philosopher problem!\n");
	if (!(condition_error(ac, av) == 0))
		return (1);
	init_value_av(av, &rules);
	init_value_philo(av, rules);
	manage_thread();
	return (0);
}