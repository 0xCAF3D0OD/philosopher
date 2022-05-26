/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:18:17 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/26 19:52:23 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_time(void)
{
    struct timeval tv;
    int    time;

    gettimeofday(&tv, NULL);
    time = (tv.tv_usec * 1000) + (tv.tv_sec / 1000);
    return (time);
}

int main(int ac, char **av)
{
	(void) ac;
	int i = -1;
	int first_time = 0;
	int eating_time = 0;
	int time_death = ft_atoi(av[1]);

	first_time = init_time();
	while (++i < 10)
	{
		printf("i am eating\n");
		eating_time =  (init_time() - time_death);
		printf ("eating time %d\n", eating_time);
		usleep(time_death);
	}
	return (0);
}