
#include "philo.h"

// pthread_mutex_t essais;
void	mutex_and_threads_function(t_data *rules)
{
//	printf("ID -> %d\n", rules->philos[1].id);
	lauche_mutex(rules);
//	printf("ID -> %d\n", rules->philos[1].id);
	lauche_threads(rules);
}

void	init_info_philos(t_data *rules)
{
	int i;
	
	i = -1;
	while (++i < rules->numb_of_philo)
	{
		rules->philos[i].id = i;
		rules->philos[i].left_fork_id = &(rules->forks[i]);
		if (i == rules->numb_of_philo)
			rules->philos[i].right_fork_id = &(rules->forks[0]);
		else
			rules->philos[i].left_fork_id = &(rules->forks[i + 1]);
	}
	rules->philos->t_last_meal = 0;
	rules->philos->x_ate = 0;
	rules->philos->is_dead = 0;
}

void	condition_philosophers(char **av, t_data *rules)
{
	rules->numb_of_philo = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);	
	rules->time_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->forks = malloc(sizeof(t_data) * rules->numb_of_philo);
	rules->philos = (t_philos*) malloc(sizeof(t_philos) * rules->numb_of_philo);
	rules->philos = (t_philos*) malloc(sizeof(t_philos) * rules->numb_of_philo);
	rules->philos->left_fork_id = malloc(sizeof(t_philos) * rules->numb_of_philo);
	rules->philos->right_fork_id = malloc(sizeof(t_philos) * rules->numb_of_philo);
	init_info_philos(rules);
	timestamp();
}

int	condition_erreur(int ac)
{
	if (ac < 1 || ac > 5)
		return (1);
	return (0);
}

int	main (int argc, char **argv)
{
    t_data		*rules;
    int			ret;

	ret = 0;
	rules = (t_data*) malloc(sizeof(t_data));
	// pthread_mutex_init(&essais, NULL);
    if ((ret = condition_erreur(argc)))
    	ft_print(ret, 0);
	condition_philosophers(argv, rules);
	mutex_and_threads_function(rules);
	free(rules->forks);
	free(rules);
	return (0);
}