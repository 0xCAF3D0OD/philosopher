/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:06:18 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/12 15:55:41 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

// int fct(void)
// {
// 	int i;
// 	int	ret;

// 	i = 0;
// 	ret = 0;
// 	printf("creation du thread du magasin\n");
// 	ret = pthread_create(&thread, NULL, store, NULL);
// 	if (!ret)
// 	{
// 		i = 0;
// 		printf("creation des threads clients\n");
// 		while (i < NB_CLIENTS)
// 		{
// 			ret = pthread_creat(&thread_client[i], NULL, client, NULL)
// 			if (ret)
// 				printf(stderr, "%s\n", strerror(ret));
// 			i++;
// 		}
// 	}
// 	else
// 		printf(stderr, "%s\n", strerror(ret));
// 	i = 0;
// 	while (i < NB_CLIENTS)
// 	{
// 		pthread_join(&thread_clients[i], NULL);
// 	}
// 	pthread_join(&thread_store, NULL);
// 	return (0);
// }
