/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:04:29 by gbabeau           #+#    #+#             */
/*   Updated: 2021/05/31 17:07:31 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_time(void)
{
	struct timeval	time1;
	long long		time;

	gettimeofday(&time1, DST_NONE);
	time = time1.tv_usec + time1.tv_sec * 1000000;
	return (time);
}

void	*test_to_live(void *arg)
{
	t_philosopher	*philo;
	long long		time;

	time = 0;
	philo = (t_philosopher *)arg;
	philo->last_eat = ft_time();
	while ((philo->chrono->number_of_each == -1
			|| philo->each < philo->chrono->number_of_each))
	{
		philo->chrono->time = ft_time();
		if ((philo->chrono->time - philo->last_eat
				- philo->chrono->time_to_die) > 0)
		{
			philo->chrono->status = 0;
			philo->etat = 5;
			philo->etat_str = STR_DIED;
			display(philo, STR_DIED);
			exit(1);
		}
	}
	if (--philo->chrono->etat == 0)
		sem_wait(philo->chrono->general);
	return (NULL);
}

void	init_data(int argv, char **argc, t_chrono *all)
{
	all->number_of_philosopher = atoi(argc[1]);
	all->time_to_die = atoi(argc[2]) * 1000;
	all->time_to_eat = atoi(argc[3]) * 1000;
	all->time_to_sleep = atoi(argc[4]) * 1000;
	all->etat = all->number_of_philosopher;
	all->status = 1;
	if (argv == 6)
		all->number_of_each = atoi(argc[5]);
	else
		all->number_of_each = -1;
}

void	finish(t_chrono *all)
{
	int	i;

	i = 0;
	usleep(1000);
}

int	main(int argv, char **argc)
{
	t_chrono			all;
	t_philosopher		*philosophers;
	pthread_mutex_t		*fork;
	int					i;
	long long			time;

	time = ft_time();
	i = -1;
	init_data(argv, argc, &all);
	philosophers = malloc(sizeof(t_philosopher) * all.number_of_philosopher);
	init_philosophers(all.number_of_philosopher, &all,
		philosophers);
	i = -1;
	while (1)
		;
	return (0);
}
