/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:59:36 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/31 02:52:32 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *nptr, int *y, int i, t_Pile *pile_a, t_Pile *pile_b)
{
	int	pair;
	int	nb;

	pair = 1;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (!nptr[i])
		return (*y = -1, 0);
	if (nptr[i] == '-')
	{
		pair *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		if (nb != ((10 * nb + nptr[i] - 48) / 10))
			overflow_int(pile_a, pile_b);
		nb = 10 * nb + nptr[i] - 48;
		i++;
	}
	*y += i;
	return (nb * pair);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
