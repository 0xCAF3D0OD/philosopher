/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:33:37 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/14 14:39:44 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *manage_philo(void *args)
{
	(void) 			args;
	t_thread		*thread;
	
	thread = NULL;
	pthread_mutex_lock (&thread->fork_d);
	pthread_mutex_lock (&thread->fork_g);
	printf("i'am eating\n");
	pthread_mutex_unlock(&thread->fork_d);
	pthread_mutex_unlock(&thread->fork_g);
	return (NULL);
}

void	board_philo(int ret)
{
	t_thread	thread;
	
	ret = pthread_create(&thread.new_thread, NULL, manage_philo, NULL);
	if (ret == -1)
		ft_printf("%d\n", ret);
	manage_philo(NULL);
	pthread_join(thread.new_thread, NULL);
	printf("the end\n");
}

static int    init_time(void)
{
    struct timeval tv;
    int    time;

    gettimeofday(&tv, NULL);
    time = tv.tv_sec * 1000;
    time += (tv.tv_usec / 1000);
    return (time);
}

int        ft_time(void)
{
    static int    time;

    if (time == 0)
        time = init_time();
    return (init_time() - time);
}

void	init_philo(t_data *data)
{
	int i;

	i = -1;
	while (++i <= data->number_of_philosopher)
	{
		data[i].left_fork_id = i;
		data[i].right_fork_id = (i + 1) % data->number_of_philosopher;
	}

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
}

int condition_philo(int ac, char **av, t_data	*data)
{
	(void)	data;
	if (!av[1] && ac < 2)
	{
		printf("no arguments or less\n");
		return (1);		
	}
	if (ft_atoi(av[1]) < 2)
	{
		printf("less philosopher\n");
		return (1);
	}
}

int main(int ac, char **av)
{
	int 		ret;
	int			i;
	t_data		*data;

	
	data = NULL;
	ret = 0;
	i = 0;
	if (condition_philo(ac, av, data) == 1)
		return (1);
	philo_manager(av, &data);
	init_philo(data);
	ft_time();
	while (1)
	{
		usleep(1000000);
		board_philo(ret);
	}
	return (0);	
}
