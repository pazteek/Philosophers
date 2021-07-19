/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:51:12 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/19 18:05:06 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_fork(int number_of_philosopher,
		t_philosopher *philosophers)
{
	int				i;
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t) * number_of_philosopher);
	i = -1;
	while (++i < number_of_philosopher)
	{
		pthread_mutex_init(&fork[i], NULL);
	}
	i = -1;
	while (++i < number_of_philosopher)
	{
		philosophers[i].chrono->fork = fork;
		philosophers[i].num = i;
		if (0 == i % 2)
		{
			philosophers[i].fork[0] = i;
			philosophers[i].fork[1] = (i + 1) % number_of_philosopher;
		}
		else
		{
			philosophers[i].fork[1] = i;
			philosophers[i].fork[0] = (i + 1) % number_of_philosopher;
		}
	}
}

void	init_pthread(int number_of_philosopher,
		t_philosopher *philosophers)
{
	int				i;
//	pthread_t		thread_id[200];


	i = -1;
	philosophers[0].chrono->start = ft_time();
	philosophers[0].chrono->status = 1;
	while (++i < number_of_philosopher && philosophers[0].chrono->status != 0)
	{
		philosophers[i].last_eat = ft_time();
//	pthread_create(&thread_id[i], NULL, test_to_live, &philosophers[i]);
		pthread_create(&philosophers[i].thread_id,
			NULL, test, &philosophers[i]);
	}
}

void	init_philosophers(int number_of_philosopher,
		t_chrono *all, t_philosopher *philosophers)
{
	int	i;

	i = -1;
	while (++i < all->number_of_philosopher)
	{
		philosophers[i].chrono = all;
		philosophers[i].each = 0;
	}
	init_fork(number_of_philosopher, philosophers);
	init_pthread(number_of_philosopher, philosophers);
	if (philosophers[0].chrono->status != 0)
		pthread_mutex_lock(all->general);
			printf("A\n");
	pthread_mutex_lock(all->general);
	usleep(2000);
	i = -1;
	while (++i < all->number_of_philosopher)
	{
		pthread_mutex_unlock(&all->fork[i]);
		pthread_mutex_destroy(&all->fork[i]);
	}
}
