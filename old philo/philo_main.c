/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:25:25 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/20 16:50:28 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philos *philo)
{
	t_data *rules;

	rules = (t_data *) philo->rules;
	
	pthread_mutex_lock(&(rules->forks[*philo->left_fork_id]));
	pthread_mutex_lock(&(rules->forks[*philo->right_fork_id]));
	printf("is eating\n");
	pthread_mutex_unlock(&(rules->forks[*philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[*philo->right_fork_id]));
}

void	*ft_thread(void *philo_void)
{
	t_philos	*philos;
	t_data		*rules;
	int i = 0;

	rules = (t_data*) philo_void;
	philos = rules->philo;
	while (i < 5)
	{
		ft_eating(philos);
	}
	return (NULL);
}

void	init_thread(t_data *rules)
{
	int	i;

	i = 0;
	while(++i <= rules->numb_of_philo)
	{
		pthread_create(&rules->philo[i].thread_id, NULL, ft_thread, rules);
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
	}
}

int	mutex_init(t_data *rules)
{
	int	i;
	int ret;
	(void) rules;

 	i = -1;
	ret = 0;
	ret = pthread_mutex_init(&(rules->forks[i]), NULL);
	while (++i <= rules->numb_of_philo)
	{
		printf("%d", i);
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	return (0);
}

int	init_value_av(char **av, t_data **rules)
{
	*rules = (t_data *) malloc(sizeof(t_data));
	(*rules)->numb_of_philo = ft_atoi(av[1]);
	(*rules)->time_to_die = ft_atoi(av[2]);
	(*rules)->time_eat = ft_atoi(av[3]);
	(*rules)->time_to_sleep = ft_atoi(av[4]);
	(*rules)->philo = (t_philos *) malloc(sizeof(t_philos)
			* (*rules)->numb_of_philo);
	if (mutex_init(*rules))
		return (1);
	return (0);
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

	printf("welcome to the philosopher problem!\n");
	if (condition_error(ac, av))
		return (printf("wrong input = 4 input required && mini 2 philo\n"));
	init_value_av(av, &rules);
	init_value_philo(av, rules);
	init_thread(rules);
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
