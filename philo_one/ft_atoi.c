/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:55:56 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/07 18:34:22 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	signe(char *str, int *nb)
{
	int	i;
	int	a;

	i = 1;
	a = 0;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			i *= -1;
		a++;
	}
	*nb = a;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	renvoie;
	int	nombre;

	nb = 0;
	i = signe((char *)str, &nb);
	nombre = 0;
	renvoie = 0;
	while ('0' <= str[nb] && '9' >= str[nb])
	{
		nombre = str[nb] - 48;
		renvoie = renvoie + nombre;
		nb++;
		if ('0' <= str[nb] && '9' >= str[nb])
			renvoie *= 10;
	}
	return (i * renvoie);
}
