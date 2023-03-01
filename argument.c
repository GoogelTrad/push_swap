/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:13:33 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/28 19:16:02 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_Pile	*create_list(t_Pile *pile, int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (pile);
	if (!(verif_argument(ac, av)))
	{
		write(1, "Arguments invalide !\n", 21);
		return (pile);
	}
	while (i != ac)
	{
		printf("av[i] = %s\n", av[i]);
		verif_str(av[i], pile);
		i++;
	}
	return (pile);
}

void	verif_str(char *str, t_Pile *pile)
{
	int		res;
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return ;
	else if (ft_strlen(str) == 1)
	{
		res = ft_atoi(str, &i);
		insertion(pile, res);
		return ;
	}
	printf("Coucou\n");
	while (str[i])
	{
		res = ft_atoi(str + i, &i);
		if (i == -1)
			return ;
		insertion(pile, res);
	}
}

int verif_argument(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i != ac)
	{
		while (av[i][j])
		{
			if (!(!((av[i][j] < '0' || av[i][j] > '9'))) && av[i][j] != '-' && av[i][j] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}