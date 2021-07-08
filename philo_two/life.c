/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:56:37 by gbabeau           #+#    #+#             */
/*   Updated: 2021/05/31 17:04:54 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_eat(t_philosopher *philo, pthread_t thread_id)
{
	pthread_t		display_t;
	int				*a;

	sem_wait(philo->chrono->fork);
	display(philo, STR_TAKEN);
	sem_wait(philo->chrono->fork);
	display(philo, STR_TAKEN);
	philo->last_eat = ft_time();
	display(philo, STR_EAT);
	ft_usleep(ft_time(), philo->chrono->time_to_eat);
	sem_post(philo->chrono->fork);
	sem_post(philo->chrono->fork);
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
		ft_eat(philo, thread_id);
		display(philo, STR_SLEEP);
		ft_usleep(ft_time(), philo->chrono->time_to_sleep);
		display(philo, STR_THINK);
	}
	return (NULL);
}
