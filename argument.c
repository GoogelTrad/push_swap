/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:13:33 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/31 02:52:00 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Pile	*create_list(t_Pile *pile_a, t_Pile *pile_b, int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (pile_a);
	if (!(verif_argument(ac, av) && verif_signe(ac, av)))
	{
		write(2, "Error\n", 6);
		free_pile(pile_a, pile_b);
		exit(0);
	}
	while (i != ac)
	{
		verif_str(av[i], pile_a, pile_b);
		i++;
	}
	if (!verif_doublons(pile_a))
	{
		write(2, "Error\n", 6);
		free_pile(pile_a, pile_b);
		exit(0);
	}
	return (pile_a);
}

void	verif_str(char *str, t_Pile *pile_a, t_Pile *pile_b)
{
	int		res;
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return ;
	while (str[i])
	{
		res = ft_atoi(str + i, &i, 0, pile_a, pile_b);
		if (i == -1)
			return ;
		insertion(pile_a, res);
		pile_a->size++;
	}
}

int	verif_argument(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i != ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-'
				&& av[i][j] != '+' && av[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verif_doublons(t_Pile *pile)
{
	t_Element	*tmp;
	t_Element	*actu;
	int			nb;

	actu = pile->premier;
	while (actu)
	{
		nb = actu->nombre;
		tmp = actu->suivant;
		while (tmp)
		{
			if (nb == tmp->nombre)
				return (0);
			tmp = tmp->suivant;
		}
		actu = actu->suivant;
	}
	return (1);
}

int	verif_signe(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i != ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (av[i][j + 1] < '0' || av[i][j + 1] > '9')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
