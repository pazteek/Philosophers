/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:51:12 by gbabeau           #+#    #+#             */
/*   Updated: 2021/05/31 17:04:36 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <semaphore.h>

void	init_fork(int number_of_philosopher, t_philosopher *philosophers)
{
	sem_t	*fork;
	sem_t	*display;
	int		i;

	i = -1;
	display = sem_open("display", O_CREAT, O_CREAT, 1);
	sem_unlink("fork");
	fork = sem_open("fork", O_CREAT | O_EXCL, 0644, number_of_philosopher);
	while (++i < number_of_philosopher)
	{
		philosophers[i].num = i;
		philosophers[i].display = display;
		philosophers[i].chrono->fork = fork;
	}
}

void	init_pthread(int number_of_philosopher, t_philosopher *philosophers)
{
	int	i;

	i = -1;
	philosophers->chrono->general = sem_open("general", 0, O_CREAT, 1);
	sem_wait(philosophers->chrono->general);
	philosophers[0].time_to_live = ft_time();
	while (++i < number_of_philosopher)
	{
		philosophers[i].time_to_live = philosophers[0].time_to_live;
		pthread_create(&philosophers[i].thread_id,
			NULL, test, &philosophers[i]);
		usleep(200);
	}
	sem_wait(philosophers->chrono->general);
}

void	init_philosophers(int number_of_philosopher, t_chrono *all,
		t_philosopher *philosophers)
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
}
