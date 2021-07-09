/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:51:12 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/09 15:37:41 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_fork(int number_of_philosopher,
				t_philosopher *philosophers)
{
	int				i;
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t) * number_of_philosopher);
//	display = malloc(sizeof(pthread_mutex_t) * number_of_philosopher);
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
	int	i;

	i = -1;
	pthread_mutex_lock(&philosophers->chrono->general);
	philosophers[0].chrono->start = ft_time();
	while (++i < number_of_philosopher && philosophers[0].chrono->status != 0)
	{
			
		philosophers[i].last_eat = ft_time();
		pthread_create(&philosophers[i].thread_id,
			NULL, test, &philosophers[i]);
	}
}

void	init_philosophers(int number_of_philosopher,
		t_chrono *all, t_philosopher *philosophers, pthread_mutex_t *general)
{
	int	i;

	i = -1;
	all->general = *general;
	while (++i < all->number_of_philosopher)
	{
		philosophers[i].chrono = all;
		philosophers[i].each = 0;
	}
	init_fork(number_of_philosopher, philosophers);
	init_pthread(number_of_philosopher, philosophers);
}
