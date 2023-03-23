/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:25:46 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/22 16:42:19 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_3_elem(t_Pile *pile_a)
{
	int	first;
	int	second;
	int	third;

	while (!pile_trie(pile_a))
	{
		first = pile_a->premier->index;
		second = pile_a->premier->suivant->index;
		third = pile_a->premier->suivant->suivant->index;
		if (first > second)
			swap_a(pile_a);
		else if (first > second && first < third)
			rotate_a(pile_a);
		else if (first < second && second > third)
			rev_rotate_a(pile_a);
	}
}

t_Element	*get_inf(t_Pile *a, int *i)
{
	int			j;
	t_Element	*min;
	t_Element	*tmp;

	tmp = a->premier;
	min = a->premier;
	j = 0;
	*i = 0;
	while (tmp)
	{
		if (tmp->index < min->index)
		{
			*i = j;
			min = tmp;
		}
		j++;
		tmp = tmp->suivant;
	}
	return (min);
}

void	tri_5_elem(t_Pile *pile_a, t_Pile *pile_b)
{
	int			i;
	t_Element	*tmp;

	while (pile_a->size > 3)
	{
		tmp = get_inf(pile_a, &i);
		while (pile_a->premier != tmp)
		{
			if (i < 3)
				rotate_a(pile_a);
			else
				rev_rotate_a(pile_a);
		}
		push_b(pile_a, pile_b);
	}
	tri_3_elem(pile_a);
	while (pile_b->size)
		push_a(pile_a, pile_b);
}

void	stacking(t_Pile *pile, int x, int y, int limite)
{
	if (x <= y)
	{
		while (x-- > 0)
			rotate_a(pile);
	}
	else if (y < x)
	{
		while (y++ < limite)
			rev_rotate_a(pile);
	}
}
