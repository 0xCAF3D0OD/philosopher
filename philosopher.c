
#include "philo.h"

void	mutex_and_threads_function(t_data *data, t_rules *rules, t_philos *philos)
{
	lauche_mutex(data, rules, philos);
	lauche_threads(data, rules, philos);
}

void	init_info_philos(t_data *data, t_rules *rules, t_philos *philos)
{
	int i;
	
	i = -1;
	while (++i < rules->numb_of_philo)
	{
		philos[i].id = i;
		philos[i].left_fork_id = &(data->forks[i]);
		philos[i].t_last_meal = 0;
		philos[i].x_ate = 0;
		philos[i].is_dead = 0;
		philos[i].rules = rules; 
		if (i == rules->numb_of_philo)
			philos[i].right_fork_id = &(data->forks[0]);
		else
			philos[i].left_fork_id = &(data->forks[i + 1]);
	}
}

void	condition_philosophers(t_data *data, t_rules *rules)
{
	t_philos	*philos;
	
	data->forks = malloc(sizeof(t_data) * rules->numb_of_philo);
	philos = (t_philos*) malloc(sizeof(t_philos) * rules->numb_of_philo);
	philos->left_fork_id = malloc(sizeof(t_philos) * rules->numb_of_philo);
	philos->right_fork_id = malloc(sizeof(t_philos) * rules->numb_of_philo);
	init_info_philos(data, rules, philos);
	mutex_and_threads_function(data, rules, philos);
	timestamp();
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
	if (ac < 1 || ac > 5)
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
    	ft_print(ret, 0);
	condition_rules_args(argc, argv, rules);
	condition_philosophers(data, rules);
	free(data->forks);
	free(rules);
	return (0);
}