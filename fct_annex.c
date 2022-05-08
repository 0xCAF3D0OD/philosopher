/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_annex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:23:24 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/07 16:54:14 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *nptr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		    || nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	j = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			j = -1;
			i++;
		}	
		else if (nptr[i] == '+')
			i++;
	}
	k = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		k = k * 10 + (nptr[i++] - '0');
	return (k * j);
}

// int funmct(void)
// {
// 	struct timeval time;
// 	size_t var;

// 	var = (time.tv_sec * 1000) + (time.tv_usec / 1000);
// 	gettimeofday(&time, NULL);
// 	printf("%zu\n", var);
// 	// printf("%ld\n", time.tv_sec);
// 	// printf("%d\n", time.tv_usec);
// 	return (0);
// }