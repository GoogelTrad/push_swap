/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_large.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:04:27 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/21 20:15:32 by cmichez          ###   ########.fr       */
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

int	from_top(t_Pile *pile, int min, int max)
{
	t_Element *tmp;
	int	i;
	int j;

	i = 0;
	j = pile->size / 2;
	tmp = pile->premier;
	while (j < pile->size)
	{
		if (tmp->index < max && tmp->index >= min)
			return (i); 
		i++;
		j++;
		tmp = tmp->suivant;
	}
	return (0);
}

int	from_bot(t_Pile *pile, int min, int max)
{
	t_Element *tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp = pile->premier;
	while (j < pile->size / 2)
	{
		if (tmp->index < max && tmp->index >= min)
			return (i);
		i++;
		j++;
		tmp = tmp->suivant;
	}
	return (0);
}

void	stacking_pile(t_Pile *pile_a, t_Pile *pile_b)
{
	int i;
	int	x;
	int	y;
	int max_size;
	int limite[2];

	limite[0] = 0;
	limite[1] = pile_a->size / 5;
	max_size = pile_a->size;
	while (pile_a->size)
	{
		i = 0;
		while (i < max_size / 5)
		{
			x = from_bot(pile_a, limite[0], limite[1]);
			y = from_top(pile_a, limite[0], limite[1]);
			if (x <= y)
			{
				while (x-- > 0)
					rotate_a(pile_a);
				push_b(pile_a, pile_b);
			}
			else if (y < x)
			{
				while (y++ < max_size)
					rev_rotate_a(pile_a);
				push_b(pile_a, pile_b);	
			}
			i++;	
		}
		limite[0] = limite[1];
		limite[1] += max_size / 5;
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
