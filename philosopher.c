
#include "philo.h"

void	ft_print(int ret)
{
	if (ret == 1)
    	printf("wrong input or to much arguments\n");
}

void	*thread_manager(void *void_philos)
{
	t_data		*rules;
	t_philos	*philos;
	int			i;

	i = 0;
	philos = (t_philos*) void_philos;
	rules = philos->rules;
	while (!(rules->is_dead))
	{
		philos_is_eating(philos);
	}
}
void	lauche_threads(t_data *rules, t_philos *philos)
{
	int	time;
	int	i;

	time = timestamp();
	i = -1;
	while (++i < rules->numb_of_philo)
	{
		pthread_create(&(philos[i].thread_id), NULL, thread_manager, &rules);
		philos->t_last_meal = timestamp() - time;
	}
	ft_printf(" %d\n", philos->t_last_meal);
	// while ()
}

void	lauche_mutex(t_data *rules)
{
	int	i;

	i = -1;
	while (++i < rules->numb_of_philo)
	{
		pthread_mutex_init(&(rules->forks[i]), NULL);
	}
}

void	mutex_and_threads_function(t_data *rules, t_philos *philos)
{
	lauche_mutex(rules);
	lauche_threads(rules, philos);
}

static int	init_timestamp(void)
{
    struct timeval tv;
    int    time;

    gettimeofday(&tv, NULL);
    time = (tv.tv_usec * 1000) + (tv.tv_sec / 1000);
    return (time);
}

int	timestamp(void)
{
	static int time;

	if (time == 0)
		time = init_timestamp();
	return (init_timestamp() - time);
}

void	init_info_philos(t_data *rules, t_philos *philos)
{
	int i;
	
	i = -1;
	while (++i < rules->numb_of_philo)
	{
		philos[i].id = i;
		philos[i].left_fork_id = &(rules->forks[i]);
		if (i == rules->numb_of_philo)
			philos[i].right_fork_id = &(rules->forks[0]);
		else
			philos[i].left_fork_id = &(rules->forks[i + 1]);
	}
	philos->t_last_meal = 0;
	philos->x_ate = 0;
}

int	condition_philosophers(char **av, t_data **rules, t_philos **philos)
{
	*rules = (t_data*) malloc(sizeof(t_data));
	(*rules)->numb_of_philo = ft_atoi(av[1]);
	(*rules)->time_eat = ft_atoi(av[2]);
	(*rules)->time_to_die = ft_atoi(av[3]);
	(*rules)->time_to_sleep = ft_atoi(av[4]);
	(*rules)->forks = malloc(sizeof(t_data) * (*rules)->numb_of_philo);
	*philos = (t_philos*) malloc(sizeof(t_philos) * (*rules)->numb_of_philo);
	(*philos)->left_fork_id = malloc(sizeof(t_philos) * (*rules)->numb_of_philo);
	(*philos)->right_fork_id = malloc(sizeof(t_philos) * (*rules)->numb_of_philo);
	init_info_philos(*rules, *philos);
	timestamp();
	return (rules);
}

int	condition_erreur(int ac, char **av, t_data *rules, t_philos *philos)
{
	(void)	av;
	(void)	rules;
	(void)	philos;

	if (ac < 1 && ac > 5)
		return (1);
	return (0);
}

int	main (int argc, char **argv)
{
    t_data		*rules;
    t_philos	*philos;
    int			ret;

	ret = 0;
    if ((ret = condition_erreur(argc, argv, rules, philos)))
    	ft_print(ret);
	condition_philosophers(argv, &rules, &philos);
	mutex_and_threads_function(rules, philos);
	free(rules->forks);
	free(rules);
	free(philos);
	return (0);
}