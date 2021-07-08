/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:56:37 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/07 19:50:51 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->chrono->fork[philo->fork[0]]);
//	display(philo, STR_TAKEN);
	pthread_mutex_lock(&philo->chrono->fork[philo->fork[1]]);
//	display(philo, STR_TAKEN);
	philo->last_eat = ft_time();
//	display(philo, STR_EAT);
	ft_usleep(ft_time(), philo->chrono->time_to_eat);
	pthread_mutex_unlock(&philo->chrono->fork[philo->fork[0]]);
	pthread_mutex_unlock(&philo->chrono->fork[philo->fork[1]]);
	if (philo->chrono->number_of_each != -1)
		philo->each++;
}

void	*test(void *arg)
{
	t_philosopher	*philo;
	pthread_t		thread_id;

	philo = (t_philosopher *)arg;
	philo->chrono->time = ft_time();
	pthread_create(&thread_id, NULL, test_to_live, philo);
	philo->etat = 1;
	philo->etat_str = NULL;
	while ((philo->chrono->number_of_each == -1
			|| philo->chrono->number_of_each > philo->each)
		&& philo->chrono->status == 1)
	{
		ft_eat(philo);
//		display(philo, STR_SLEEP);
		ft_usleep(ft_time(), philo->chrono->time_to_sleep);
//		display(philo, STR_THINK);
	}
	return (NULL);
}
