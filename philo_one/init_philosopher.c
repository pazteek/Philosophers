/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:51:12 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/20 00:11:05 by gbabeau          ###   ########.fr       */
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
		if (i % 2 == 0)
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

	i = -1;
	philosophers[0].chrono->start = ft_time();
	philosophers[0].chrono->status = 1;
	while (++i < number_of_philosopher)
	{
		philosophers[i].last_eat = ft_time();
		pthread_create(&philosophers[i].thread_id,
			NULL, test, &philosophers[i]);
		pthread_detach(philosophers[i].thread_id);
	}
}

static void	life_2(t_philosopher *philo)
{
	int	i;

	i = 0;
	while ((philo[i].chrono->number_of_each == -1
			|| philo[i].chrono->number_of_philosopher
			!= philo[i].chrono->finish) && philo[i].chrono->status != 0)
	{
		if ((philo[i].chrono->number_of_each == -1
				|| philo[i].each < philo[i].chrono->number_of_each)
			&& (ft_time() - philo[i].last_eat > philo[i].chrono->time_to_die))
		{
			philo[i].chrono->status = 0;
			philo[i].chrono->time = ft_time();
			philo[i].etat = 5;
			pthread_mutex_lock(philo[i].chrono->display);
			printf("%ld %d %s\n", (long)((ft_time() - philo[i].chrono->start)
					/1000), philo[i].num + 1, STR_DIED);
			philo[i].chrono->status = 0;
			pthread_mutex_unlock(philo[i].chrono->general);
		}
		i++;
		if (i == philo[0].chrono->number_of_philosopher)
			i = 0;
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
	life_2(philosophers);
	i = -1;
	while (++i < all->number_of_philosopher)
	{
		pthread_mutex_unlock(&all->fork[i]);
		pthread_mutex_destroy(&all->fork[i]);
	}
}
