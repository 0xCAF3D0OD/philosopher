/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:20:54 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/08 16:03:05 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(int ret, int i, long long time, int timer)
{
	if (timer > 0 && ret == 7)
		printf("\n%lld	| philos [%d] is eating	🍽   x %d\n\n",time , i + 1, timer);
	else if (timer == 0 && ret == 7)
		printf("\n%lld	| philos [%d] is eating	🍽\n\n",time , i + 1);
	if (ret == 0)	
    	printf("the 🍝 is ready\n");
	if (ret == 1)
    	printf("wrong input or to much arguments\n");
	if (ret == 3)
		printf("%lld	| philos [%d] take the left	[🛑]🍴\n",time , i + 1);
	if (ret == 4)
		printf("%lld	| philos [%d] take the right	[🛑]🍴\n",time , i + 1);
	if (ret == 5)
		printf("%lld	| philos [%d] let the left	[🟢]🍴\n",time , i + 1);
	if (ret == 6)
		printf("%lld	| philos [%d] let the right	[🟢]🍴\n",time , i + 1);	
	if (ret == 8)
		printf("%lld	| philos [%d] is dead		[💀]\n",time , i + 1);
	if (ret == 9)
		printf("%lld	| philos [%d] is sleeping	[😴]\n",time , i + 1);
	if (ret == 10)	
		printf("%lld	| philos [%d] is thinking	[🤔]\n",time , i + 1);
}
