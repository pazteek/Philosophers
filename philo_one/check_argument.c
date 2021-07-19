/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:29:04 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/12 12:12:06 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_compare_c_to_s(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (str[i++] == c)
			return (1);
	return (0);
}

int	ft_compare_s_to_s(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0')
		if (ft_compare_c_to_s(str1[i++], str2))
			return (1);
	return (0);
}

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

int	check_init(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	if (ft_compare_c_to_s(str[0], "0123456789") == 0)
		return (0);
	if (str[0] == '-' && str[1] == '0')
		return (0);
	if (str[0] == '0' && str[1] != '\0')
		return (0);
	while (str[++i] != '\0')
		if (ft_compare_c_to_s(str[i], "0123456789") == 0)
			return (0);
	if (str[0] == '-')
	{
		--i;
		if (i > 10 || ((i == 10)
				&& (str[0] > '2' || ft_atoi(str) > 0)))
			return (0);
	}
	else if (i > 10 || ((i == 10)
			&& (str[1] > '2' || ft_atoi(str) < 0)))
		return (0);
	return (1);
}
