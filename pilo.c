/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pilo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:33:37 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/06 17:42:28 by kdi-noce         ###   ########.fr       */
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

void condition_philo(int ac, char **av)
{
	t_data	*data;

	data->nb_philo = av[1];
	data->nb_fork = av[1];
	data->time_die = av[2];
	data->time_eat = av[3];
	data->nb_philo = av[4];
	if (data->nb_philo < 2)
		printf("less philo\n", exit(1));
}

int main(int ac, char **av)
{
	int 		ret;

	ret = -1;
	condition_philo(ac, av);
	while (++ret < 10)
		board_philo(ret);
	return (0);	
}
