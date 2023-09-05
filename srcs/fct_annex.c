/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_annex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:23:24 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/08/16 21:52:49 by kdi-noce         ###   ########.fr       */
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

int	the_prohibited_nbr(char *av)
{
	char	*str;
	int		i;

	i = 0;
	str = av;
	while (str[i])
		i++;
	if (i == 3)
	{
		if (str[0] == '4' && str[1] == '1' && str[2] == '0')
			return (1);
	}
	return (0);
}
