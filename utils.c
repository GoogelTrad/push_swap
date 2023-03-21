/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:59:36 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/21 14:55:01 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *nptr, int *y)
{
	int	pair;
	int	i;
	int	nb;

	pair = 1;
	nb = 0;
	i = 0;
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

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	*add_tab(t_Pile *pile_a)
{
	t_Element	*temp;
	int			*tab;
	int			i;

	i = 0;
	temp = pile_a->premier;
	tab = malloc(sizeof(int) * (pile_a->size + 1));
	temp = pile_a->premier;
	while (temp->suivant)
	{
		tab[i] = temp->index;
		i++;
		temp = temp->suivant;
	}
	return (tab);
}