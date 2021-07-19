/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:56:37 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/19 18:19:32 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long long time, long long time_2)
{
	while (ft_time() < time + time_2)
		usleep(100);
}

static int	ft_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->chrono->fork[philo->fork[0]]);
	if (philo->chrono->status == 0 || display(philo, STR_TAKEN) == 0)
		return (0);
	pthread_mutex_lock(&philo->chrono->fork[philo->fork[1]]);
	if (philo->chrono->status == 0 || display(philo, STR_TAKEN) == 0)
		return (0);
	philo->last_eat = ft_time();
	if (philo->chrono->status == 0 || display(philo, STR_EAT) == 0)
		return (0);
	ft_usleep(ft_time(), philo->chrono->time_to_eat);
	pthread_mutex_unlock(&philo->chrono->fork[philo->fork[0]]);
	pthread_mutex_unlock(&philo->chrono->fork[philo->fork[1]]);
	if (philo->chrono->number_of_each != -1)
		philo->each++;
	return (1);
}

void	*test(void *arg)
{
	t_philosopher	*philo;
	pthread_t		thread_id;

	philo = (t_philosopher *)arg;
	pthread_create(&thread_id, NULL, test_to_live, philo);
	philo->etat = 1;
	philo->etat_str = NULL;
	while ((philo->chrono->number_of_each == -1
			|| philo->each <= philo->chrono->number_of_each)
		&& philo->chrono->status == 1)
	{
		if (ft_eat(philo) == 0)
			return (NULL);
		ft_usleep(ft_time(), philo->chrono->time_to_sleep);
		if (philo->chrono->number_of_each == philo->each)
		{
			philo->chrono->finish++;
			usleep(200);
			if (philo->chrono->finish == philo->chrono->number_of_philosopher)
				pthread_mutex_unlock(philo->chrono->general);
			return (NULL);
		}
		if (display(philo, STR_SLEEP) == 0)
			return (NULL);
		display(philo, STR_THINK);
	}
	return (NULL);
}
