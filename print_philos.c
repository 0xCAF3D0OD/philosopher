/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:20:54 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/06 17:58:25 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(int ret, int i, long long time)
{
	if (ret == 0)
    	printf("the 🍝 is ready\n");
	if (ret == 1)
    	printf("wrong input or to much arguments\n");
	if (ret == 3)
		printf("%lld | philos %d take the left	🛑🍴\n",time , i + 1);
	if (ret == 4)
		printf("%lld | philos %d take the right	🛑🍴\n",time , i + 1);
	if (ret == 5)
		printf("%lld | philos %d let the left	🟢🍴\n",time , i + 1);
	if (ret == 6)
		printf("%lld | philos %d let the right	🟢🍴\n",time , i + 1);
	if (ret == 7)
		printf("%lld | philos %d is eating	🍽\n",time , i + 1);
	if (ret == 8)
		printf("%lld | philos %d is	💀\n",time , i + 1);
	if (ret == 9)
		printf("%lld | philos %d is	😴\n",time , i + 1);
	if (ret == 10)
		printf("%lld | philos %d is	🤔\n",time , i + 1);
}
