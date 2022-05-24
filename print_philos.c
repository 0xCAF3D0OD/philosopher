/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:20:54 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/24 09:34:28 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
