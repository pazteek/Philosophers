/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:59:23 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/09 14:51:59 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
static void	*ft_action(void	*arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	printf("%ld %d %s\n", (long)((ft_time() - philo->chrono->start)
			/ 1000), philo->num + 1, philo->etat_str);
	return (0);
}
*/

int	display(t_philosopher philo, char *etat)
{
	philo.etat_str = etat;
	
	if (philo.chrono->status != 0)
	{
		pthread_mutex_lock(&philo.chrono->display);
		(printf("%ld %d %s\n", (long)((ft_time() - philo.chrono->start)
			/ 1000), philo.num + 1, etat));
	//if (philo.etat != 5)
		pthread_mutex_unlock(&philo.chrono->display);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long	nbr;

	nbr = nb;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	nbr = nbr % 10 + 48;
	write(fd, &nbr, 1);
}

