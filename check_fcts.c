/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:24:55 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/24 17:30:15 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	check_if_dead(t_data *rules)
{
	long long	time;
	long long	ret;
	int			i;
	
	time = timestamp();
	ret = 0;
	i = -1;
	// ft_printf("%d\n", rules->numb_of_philo);
	while (++i < rules->numb_of_philo)
	{
		ret = timestamp() - time;
		if (ret > rules->time_to_die)
		{	
			rules->philos->is_dead++;
			break ;
		}
	}
	return (0);
}