/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_large.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:04:27 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/21 17:48:41 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_large(t_Pile *pile_a, t_Pile *pile_b)
{
	t_Element *tmp;
	int	i;
	
	stacking_pile(pile_a, pile_b);
	while (pile_b->size)
	{
		tmp = get_sup(pile_b, &i);
		while (pile_b->premier != tmp)
		{
			if (i < pile_b->size / 2)
				rotate_b(pile_b);
			else
				rev_rotate_b(pile_b);
		}
		push_a(pile_a, pile_b);
	}
}

void	stacking_pile(t_Pile *pile_a, t_Pile *pile_b)
{
	int	i;
	int	total;
	int	minus;
	t_Element	*tmp;

	minus = pile_a->size / 5;
	total = pile_a->size - minus;
	i = 0;
	while (pile_a->size)
	{
		total -= minus;
		while (pile_a->size >= total)
		{
			tmp = get_inf(pile_a, &i);
			while (pile_a->premier != tmp)
			{
				if (i <= pile_a->size / 2)
					rotate_a(pile_a);
				else
					rev_rotate_a(pile_a);
			}
			push_b(pile_a, pile_b);
		}
	}	
}

t_Element	*get_sup(t_Pile *a, int *i)
{
	int 		j;
	t_Element	*max;
	t_Element	*tmp;

	tmp = a->premier;
	max = a->premier;
	j = 0;
	*i = 0;
	while (tmp)
	{
		if (tmp->index > max->index)
		{
			*i = j;
			max = tmp;
		}
		j++;
		tmp = tmp->suivant;
	}
	return (max);
}
