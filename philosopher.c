
#include "philo.h"

// pthread_mutex_t essais;

static long long	init_timestamp(void)
{
    struct timeval tv;
    long long    time;

    gettimeofday(&tv, NULL);
    time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (time);
}

long long	timestamp(void)
{
	static long long time;

	if (time == 0)
		time = init_timestamp();
	return (init_timestamp() - time);
}

void	ft_print(int ret, int i)
{
	if (ret == 1)
    	printf("wrong input or to much arguments\n");
	if (ret == 3)
		printf("philos %d take the left fork\n", i);
	if (ret == 4)
		printf("philos %d take the right fork\n", i);
	if (ret == 5)
		printf("philos %d put down the left fork\n", i);
	if (ret == 6)
		printf("philos %d put down the right fork\n", i);
	if (ret == 7)
		printf("philos %d is eating\n", i);
	if (ret == 8)
		printf("philos %d is dead\n", i);
}

void	philos_is_eating(t_philos *philos, int i)
{
	pthread_mutex_lock(philos->left_fork_id);
	ft_print(3, i);
	pthread_mutex_lock(philos->right_fork_id);
	ft_print(4, i);
	ft_print(7, i);
	pthread_mutex_unlock(philos->right_fork_id);
	ft_print(6, i);
	pthread_mutex_unlock(philos->left_fork_id);
	ft_print(5, i);
}

void	*thread_manager(void *void_philos)
{
	t_data		*rules;
	t_philos	*philos;
	int			i;
	// int			len;


	philos = (t_philos*) void_philos;
	rules = philos->rules;
	ft_printf("%d\n", rules->numb_of_philo);
	while (!(rules->is_dead))
	{
		i = -1;
		while (++i < 5)
		{
			philos_is_eating(philos, i);
		}
		break ;
	}
	return (NULL);
}

long long	check_if_dead(t_data *rules, t_philos *philos)
{
	long long	time;
	long long	ret;
	// int			i;
	
	(void)	philos;
	time = timestamp();
	ret = 0;
	// i = -1;
	ft_printf("%d\n", rules->numb_of_philo);
	while (!(rules->is_dead))
	{
		usleep(1000);
		ret = timestamp() - time;
		if (ret > rules->time_to_die)
		{	
			rules->is_dead++;
			break ;
			return (ret);
		}
	}
	return (0);
}

void	lauche_threads(t_data *rules, t_philos *philos)
{
	int			i;
	long long	ret;
	

	i = -1;
	while (++i < rules->numb_of_philo)
	{
		pthread_create(&(philos[i].thread_id), NULL, thread_manager, &rules);
	}
	if ((ret = check_if_dead(rules, philos)))
	{
		ft_print(8, 0);
	}
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
	rules->is_dead = 0;
}

void	condition_philosophers(char **av, t_data **rules, t_philos **philos)
{
	*rules = (t_data*) malloc(sizeof(t_data));
	(*rules)->numb_of_philo = ft_atoi(av[1]);
	(*rules)->time_to_die = ft_atoi(av[2]);	
	(*rules)->time_eat = ft_atoi(av[3]);
	(*rules)->time_to_sleep = ft_atoi(av[4]);
	(*rules)->forks = malloc(sizeof(t_data) * (*rules)->numb_of_philo);
	*philos = (t_philos*) malloc(sizeof(t_philos) * (*rules)->numb_of_philo);
	(*philos)->left_fork_id = malloc(sizeof(t_philos) * (*rules)->numb_of_philo);
	(*philos)->right_fork_id = malloc(sizeof(t_philos) * (*rules)->numb_of_philo);
	init_info_philos(*rules, *philos);
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
    t_philos	*philos;
    int			ret;

	ret = 0;
	philos = NULL;
	// pthread_mutex_init(&essais, NULL);
    if ((ret = condition_erreur(argc)))
    	ft_print(ret, 0);
	condition_philosophers(argv, &rules, &philos);
	mutex_and_threads_function(rules, philos);
	free(rules->forks);
	free(rules);
	free(philos);
	return (0);
}