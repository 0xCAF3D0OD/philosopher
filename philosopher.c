
#include "philo.h"

void	init_info_philos(pthread_mutex_t *fork, t_rules *rules, t_philos *philos)
{
	int i;
	
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

void	condition_philosophers(t_data *data, t_rules *rules)
{
	t_philos		*philos;
	pthread_t		*ph_thread;
	pthread_mutex_t	*fork;

	data = malloc(sizeof(t_data) * rules->numb_of_philo);
	fork = malloc(sizeof(pthread_mutex_t) * rules->numb_of_philo);
	philos = (t_philos*) malloc(sizeof(t_philos) * rules->numb_of_philo);
	ph_thread = malloc(sizeof(pthread_t) * rules->numb_of_philo);
	timestamp();
	init_info_philos(fork, rules, philos);
	launche_mutex(fork, rules);
	launche_threads(ph_thread, rules, philos);
	free(fork);
	free(rules);
}

void	condition_rules_args(int ac, char **av, t_rules *rules)
{
	rules->numb_of_philo = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);	
	rules->time_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules->nb_time_to_eat = ft_atoi(av[5]);
	else
		rules->nb_time_to_eat = -1;
}

int	condition_erreur(int ac)
{
	if (ac < 1 || ac > 6)
		return (1);
	return (0);
}

int	main (int argc, char **argv)
{
    t_data		*data;
	t_rules		*rules;
    int			ret;

	ret = 0;
	data = (t_data*) malloc(sizeof(t_data));
	rules = (t_rules*) malloc(sizeof(t_rules));
	// pthread_mutex_init(&essais, NULL);
    if ((ret = condition_erreur(argc)))
    	ft_print(ret, 0, 0);
	condition_rules_args(argc, argv, rules);
	condition_philosophers(data, rules);
	// free_philos(data);
	return (0);
}