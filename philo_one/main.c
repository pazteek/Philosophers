/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+mak         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:04:29 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/07 20:06:50 by gbabeau          ###   ########.fr       */
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

void	*test_to_live(void *arg)
{
	t_philosopher	*philo;
	int i;

	i = 1;
	
	philo = (t_philosopher *)arg;
	philo->chrono->time = ft_time();
	while ((philo->chrono->number_of_each == -1
			|| philo->each < philo->chrono->number_of_each) 
			&& (i == 1))
	{
		if ((philo->last_eat - philo->chrono->start
				- philo->chrono->time_to_die) > 0)
		{
			philo->chrono->time = ft_time();
			philo->chrono->status = 0;
			i = 0;
			philo->etat = 5;
			philo->etat_str = STR_DIED;
			display(philo, STR_DIED);
		}
	}
		pthread_mutex_unlock(&philo->chrono->general);
	return (NULL);
}

void	init_data(int argv, char **argc, t_chrono *all)
{
	all->number_of_philosopher = atoi(argc[1]);
	all->time_to_die = ft_atoi(argc[2]) * 1000;
	all->time_to_eat = ft_atoi(argc[3]) * 1000;
	all->time_to_sleep = ft_atoi(argc[4]) * 1000;
	all->etat = all->number_of_philosopher;
	all->status = 1;
	if (argv == 6)
		all->number_of_each = atoi(argc[5]);
	else
		all->number_of_each = -1;
}

void	finish(t_chrono *all)
{

	(void)all;
	usleep(1000);
}

static	int	ft_test(int argv, char **argc)
{
	while (--argv != 0)
	if (check_init(argc[argv]) == 0)
		return 0;
	return (1);
}

int	main(int argv, char **argc)
{
	t_chrono			all;
	t_philosopher		*philosophers;
	pthread_mutex_t		display;
	pthread_mutex_t		general;
	int					i;

	i = -1;
	if (argv != 5 && argv != 6)
		return (0);
	if (ft_test(argv,argc) == 0)
		return (0);
	init_data(argv, argc, &all);
	pthread_mutex_init(&display, NULL);
	pthread_mutex_init(&general, NULL);
	philosophers = malloc(sizeof(t_philosopher) * all.number_of_philosopher);
	while (++i < all.number_of_philosopher)
		philosophers[i].general = general;
	all.display = display;
	init_philosophers(all.number_of_philosopher, &all,
		philosophers, &general);
	pthread_mutex_lock(&all.general);
	pthread_mutex_destroy(&display);
	pthread_mutex_destroy(&general);
	i = -1;
	while (++i < all.number_of_philosopher)
		pthread_mutex_destroy(&philosophers[i].chrono->fork[0]);
	return (0);
}
