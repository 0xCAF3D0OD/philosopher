/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:18 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/04/14 16:33:27 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

int main(void)
{
	int i;
	int	ret;

	i = 0;
	ret = 0;
	printf("creation du thread du magasin\n");
	ret = pthread_create(&thread, NULL, store, NULL);
	if (!ret)
	{
		i = 0;
		printf("creation des threads clients\n");
		while (i < NB_CLIENTS)
		{
			ret = pthread_creat(&thread_client[i], NULL, client, NULL)
			if (ret)
				printf(stderr, "%s\n", strerror(ret));
			i++;
		}
	}
	else
		printf(stderr, "%s\n", strerror(ret));
	i = 0;
	while (i < NB_CLIENTS)
	{
		pthread_join(&thread_clients[i], NULL);
	}
	pthread_join(&thread_store, NULL);
	return (0);
}
