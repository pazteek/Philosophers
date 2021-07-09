/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:56:37 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/09 16:00:46 by gbabeau          ###   ########.fr       */
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
	if (display(*philo, STR_TAKEN) == 0)
		return (0);
	pthread_mutex_lock(&philo->chrono->fork[philo->fork[1]]);
	if (display(*philo, STR_TAKEN) == 0)
		return (0);
	philo->last_eat = ft_time();
	if (display(*philo, STR_EAT) == 0)
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
	pthread_detach(thread_id);
	philo->etat = 1;
	philo->etat_str = NULL;
	while ((philo->chrono->number_of_each == -1) && philo->chrono->status == 1)
	{
		if (ft_eat(philo) == 0 || display(*philo, STR_SLEEP) == 0)
			return (NULL);
		ft_usleep(ft_time(), philo->chrono->time_to_sleep);
		if (philo->chrono->number_of_each > philo->each)
			return (NULL);
		display(*philo, STR_THINK);
	}
	return (NULL);
}
