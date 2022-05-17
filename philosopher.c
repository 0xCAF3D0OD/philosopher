/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:03:34 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/17 19:07:51 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_time(void)
{
    struct timeval tv;
    int    time;

    gettimeofday(&tv, NULL);
    time = tv.tv_sec * 1000;
	time += tv.tv_usec / 1000;
    return (time);
}

int	ft_time(void)
{
    static int    time;

    if (time == 0)
        time = init_time();
    return (init_time() - time);
}

// int	is_dead(t_data *rules)
// {
// 	while (rules->philo)
// }

void	is_eating(t_data *rules, t_philos *philos)
{
	(void) rules;
	(void) philos;
	pthread_mutex_lock(&(rules->forks[*philos->left_fork_id]));
	pthread_mutex_lock(&(rules->forks[*philos->right_fork_id]));
	printf("is eating\n");
	pthread_mutex_unlock(&(rules->forks[*philos->right_fork_id]));
	pthread_mutex_unlock(&(rules->forks[*philos->left_fork_id]));
}

void	*ft_thread_mutex(void *void_thread)
{
	t_data		*rules;
	t_philos	*philos;
	int			i = -1;

	rules = (t_data*) void_thread;
	philos = rules->philo;
	if (philos->id % 2)
		usleep(15000);
	while (++i < rules->numb_of_philo)
	{
		is_eating(rules, philos);
	}
	// if ()
	printf("fork = %d\n", (int) rules->forks);
	return (NULL);
}

void	init_thread(t_data *rules, t_philos *philos)
{
	int	i;

	i = -1;
	philos->first_time = ft_time();
	while (++i < rules->numb_of_philo)
	{
		pthread_create(&(philos[i].thread_id), NULL, ft_thread_mutex, &rules);
		philos[i].t_last_meal = ft_time();
		printf("last meal = %lld\n", philos[i].t_last_meal);
	}
}

void	init_philos_value(t_data *rules, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < rules->numb_of_philo)
	{
		philos[i].id = i;
		philos[i].left_fork_id = &i;
		philos[i].right_fork_id = &i + 1;
	}
}

void	init_mutex(t_data *rules)
{
	int	i;

	i = -1;
	while (++i <= rules->numb_of_philo)
	{
		pthread_mutex_init(&(rules->forks[i]), NULL);
	}
}

void	init_arguments(t_data *rules, t_philos *philos, char **av)
{
	(void) philos;
	rules = (t_data*) malloc(sizeof(t_data));
	rules->numb_of_philo = ft_atoi(av[1]);
	rules->time_eat = ft_atoi(av[2]);
	rules->time_to_die = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->is_dead = 0;
	printf("1: %d\n", rules->numb_of_philo);
	printf("2: %d\n", rules->time_eat);
	printf("3: %d\n", rules->time_to_die);
	printf("4: %d\n", rules->time_to_sleep);
	rules->forks = malloc(sizeof(t_data*) * rules->numb_of_philo);
	philos = malloc(sizeof(t_philos) * rules->numb_of_philo);
	init_mutex(rules);
	init_philos_value(rules, philos);
	init_thread(rules, philos);
}

void	print_error(int ret)
{
	if (ret == 1)
		printf("wrong input => must be 5 arguments");
	if (ret == 2)
		printf("wrong input => 0 philosophe");
}

int	condition_error(int ac, char **av, t_data *rules)
{
	(void) rules;
	if (ac != 5)
		return (1);
	if (ft_atoi(av[1]) < 1)
		return (2);
	return (0);
}

int main(int argc, char **argv)
{
	t_data 		*rules;
	t_philos	*philos;
	int			ret;

	rules = NULL;
	philos = NULL;
	if ((ret = condition_error(argc, argv, rules)))
		print_error(ret);
	init_arguments(rules, philos, argv);
	
}