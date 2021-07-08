/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:59:23 by gbabeau           #+#    #+#             */
/*   Updated: 2021/06/02 15:14:25 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ft_action(void	*arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	printf("%ld %d %s\n", (long)((philo->chrono->time - philo->time_to_live)
			/ 1000), philo->num + 1, philo->etat_str);
	return (0);
}

void	*display(t_philosopher *philo, char *etat)
{
	pthread_t	thread_id;

	philo->etat_str = etat;
	ft_action(philo);
	return (0);
}
