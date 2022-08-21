/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:20:54 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/08/17 22:10:55 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(int ret, int i, long long time)
{
	if (ret == 0)
		printf("the 🍝 is ready\n");
	if (ret == 8)
		printf("%lld | philos %d is	💀\n", time, i + 1);
	if (ret != 8)
	{
		if (ret == 3)
			printf("%lld | philos %d take the left	🛑🍴\n", time, i + 1);
		if (ret == 4)
			printf("%lld | philos %d take the right	🛑🍴\n", time, i + 1);
		if (ret == 5)
			printf("%lld | philos %d let the left	🟢🍴\n", time, i + 1);
		if (ret == 6)
			printf("%lld | philos %d let the right	🟢🍴\n", time, i + 1);
		if (ret == 7)
			printf("%lld | philos %d is eating	🍽\n", time, i + 1);
		if (ret == 9)
			printf("%lld | philos %d is	😴\n", time, i + 1);
		if (ret == 10)
			printf("%lld | philos %d is	🤔\n", time, i + 1);
	}
}

void	ft_print_error(int ac, int ret, char **av)
{
	if (ret == 1)
		printf("wrong input or arguments invalid\n");
	if (ret == 2)
		printf("%d. not enough args = [%d], str = [%s]\n", ret, ac, av[1]);
	if (ret == 3)
		printf("%d. not enough args = [%d], str = [%s]\n", ret, ac, av[2]);
	if (ret == 4)
		printf("%d. not enough args = [%d], str = [%s]\n", ret, ac, av[3]);
	if (ret == 5)
		printf("%d. not enough args = [%d], str [%s]\n", ret, ac, av[4]);
}
