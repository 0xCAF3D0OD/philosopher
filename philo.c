/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:33:37 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/11 16:19:29 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void *manage_philo(void *args)
// {
// 	(void) 			args;
// 	t_thread		*thread;
	
// 	thread = NULL;
// 	pthread_mutex_lock (&thread->fork_d);
// 	pthread_mutex_lock (&thread->fork_g);
// 	printf("i'am eating\n");
// 	pthread_mutex_unlock(&thread->fork_d);
// 	pthread_mutex_unlock(&thread->fork_g);
// 	return (NULL);
// }

// void	board_philo(int ret)
// {
// 	t_thread	thread;
	
// 	ret = pthread_create(&thread.new_thread, NULL, manage_philo, NULL);
// 	if (!ret)
// 		printf("null\n");
// 	manage_philo(NULL);
// 	pthread_join(thread.new_thread, NULL);
// 	printf("the end\n");
// }

void condition_philo(int ac, char **av, t_data	*data)
{
	(void)	data;
	if (!av[1] && ac < 2)
		printf("no arguments or less\n");
	if (ft_atoi(av[1]) < 2)
		printf("less philosopher\n");
}

void	philo_manager(char **av, t_data **data)
{
	int	len;
	int	i;

	i = 0;
	*data = (t_data *)malloc(sizeof(t_data));
	(*data)->number_of_philosopher = ft_atoi(av[1]);
	(*data)->fork = (*data)->number_of_philosopher;
	len = (*data)->number_of_philosopher;
	(*data)->table = NULL;
	(*data)->table = malloc(sizeof(int*) * len + 1);
	(*data)->table[len + 1] = 0;
	if (!(*data)->table)
		printf("shit\n");
	while ((*data)->table[i])
		i++;
	printf("%d\n", i);
}

int main(int ac, char **av)
{
	int 	ret;
	int		i;
	t_data	*data;
	
	data = NULL;
	ret = 0;
	i = 0;
	condition_philo(ac, av, data);
	philo_manager(av, &data);
	printf("philo = %d\n", data->number_of_philosopher);
	printf("fork = %d\n", data->fork);
	// while (1)
	// {
	// 	usleep(1);
	// 	// board_philo(ret);
	// }
	return (0);	
}
