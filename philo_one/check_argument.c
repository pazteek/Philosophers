/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:29:04 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/07 20:05:04 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
