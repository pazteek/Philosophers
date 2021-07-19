/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:05:59 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/20 00:11:39 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_time(void)
{
	struct timeval	time1;
	long long		time;

	gettimeofday(&time1, 0);
	time = time1.tv_usec + time1.tv_sec * 1000000;
	return (time);
}

void	init_data(int argv, char **argc, t_chrono *all)
{
	all->number_of_philosopher = atoi(argc[1]);
	all->time_to_die = ft_atoi(argc[2]) * 1000;
	all->time_to_eat = ft_atoi(argc[3]) * 1000;
	all->time_to_sleep = ft_atoi(argc[4]) * 1000;
	all->etat = all->number_of_philosopher;
	all->finish = 0;
	all->status = 1;
	if (argv == 6)
		all->number_of_each = atoi(argc[5]);
	else
		all->number_of_each = -1;
}

static	int	ft_test(int argv, char **argc)
{
	if (argv != 5 && argv != 6)
		return (0);
	while (--argv != 0)
		if (check_init(argc[argv]) == 0)
			return (0);
	return (1);
}

void	ft_free(t_chrono all, t_philosopher *philo,
		pthread_mutex_t *display, pthread_mutex_t *general)
{
	free(all.fork);
	free(philo);
	pthread_mutex_destroy(display);
	pthread_mutex_destroy(general);
}

void	ft_finish(t_chrono all, t_philosopher *philo,
		pthread_mutex_t *display, pthread_mutex_t *general)
{
	ft_free(all, philo, display, general);
}

int	main(int argv, char **argc)
{
	t_chrono			all;
	t_philosopher		*philosophers;
	pthread_mutex_t		*display;
	pthread_mutex_t		*general;
	int					i;

	display = malloc(sizeof(pthread_mutex_t));
	general = malloc(sizeof(pthread_mutex_t));
	i = -1;
	if (ft_test(argv, argc) == 0)
		return (0);
	init_data(argv, argc, &all);
	pthread_mutex_init(display, NULL);
	pthread_mutex_init(general, NULL);
	philosophers = malloc(sizeof(t_philosopher) * all.number_of_philosopher);
	while (++i < all.number_of_philosopher)
		philosophers[i].general = general;
	all.display = display;
	all.general = general;
	init_philosophers(all.number_of_philosopher, &all,
		philosophers);
	ft_finish(all, philosophers, display, general);
	return (0);
}
