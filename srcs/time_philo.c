/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:18:40 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/08/16 20:26:38 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	init_timestamp(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

long long	timestamp(void)
{
	static long long	time;

	if (time == 0)
		time = init_timestamp();
	return (init_timestamp() - time);
}
