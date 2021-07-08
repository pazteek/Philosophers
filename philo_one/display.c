/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:59:23 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/07 19:35:29 by gbabeau          ###   ########.fr       */
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
	philo->etat_str = etat;
	pthread_create(&philo->display_id,
			NULL, ft_action , philo);
	return (0);
}
