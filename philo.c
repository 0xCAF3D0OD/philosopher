/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:33:37 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/08 16:07:36 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *manage_philo(void *args)
{
	(void) args;
	pthread_mutex_t lock;
	
	pthread_mutex_lock (&lock);
	printf("i'am eating\n");
	pthread_mutex_unlock(&lock);
	return (NULL);
}

void	board_philo(int ret)
{
	t_thread	thread;
	
	ret = pthread_create(&thread.new_thread, NULL, manage_philo, NULL);
	if (!ret)
		printf("null\n");
	manage_philo(NULL);
	pthread_join(thread.new_thread, NULL);
	printf("the end\n");
}

int	for_malloc(char **av)
{
	int i;
	int count;

	i = -1;
	while (av[++i])
		count++;
	return (count);
}

void condition_philo(char **av)
{
	t_data	*data;
	int		count;

	if (av == NULL)
		printf("void\n");
	data = NULL;
	printf("av: %s\n", av[1]);
	// count = for_malloc(av);
	data->nb_philo = (int*) malloc(sizeof(int*) * (count + 1));
	// count = ft_atoi(av[1]);
	data->nb_philo = ft_atoi(av[1]);
	// data->nb_philo = count;
	printf("1");
	printf("%d\n", count);

	// data->nb_philo = av[1];
	// data->nb_fork = av[1];
	// data->time_die = av[2];
	// data->time_eat = av[3];
	// if (data->nb_philo < 2)
	// 	printf("less philo\n");
	// printf("%d\n",data->nb_philo);
	// printf("%d\n",data->nb_fork);
	// printf("%d\n",data->time_die);
	// printf("%d\n",data->time_eat);
}

int main(int ac, char **av)
{
	int 		ret;

	if (ac < 2)
		return (0);
	condition_philo(av);
	ret = -1;
	while (++ret < 10)
		board_philo(ret);
	return (0);	
}
