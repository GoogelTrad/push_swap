/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:25:46 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/18 01:17:08 by cmichez          ###   ########.fr       */
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
		first = pile_a->premier->nombre;
		second = pile_a->premier->suivant->nombre;
		third = pile_a->premier->suivant->suivant->nombre;
		if (first > second)
			swap_a(pile_a);
		else if (first > second && first < third)
			rotate_a(pile_a);
		else if (first < second && second > third)
			rev_rotate_a(pile_a);
	}
}

void	tri_4_elem(t_Pile *pile_a, t_Pile *pile_b)
{
	int	first;
	int	second;

	while (!pile_trie(pile_a))
	{
		first = pile_a->premier->nombre;
		second = pile_a->premier->suivant->nombre;
		if (first < second)
		{
			push_b(pile_a, pile_b);
			tri_3_elem(pile_a);
		}
		else
		{
			swap_a(pile_a);
			push_b(pile_a, pile_b);
			tri_3_elem(pile_a);
		}
		push_a(pile_a, pile_b);
	}
}

void	tri_5_elem(t_Pile *pile_a, t_Pile *pile_b)
{
	int	i;

	while (!elem_inf(pile_a, pile_a->premier->nombre))
	{
		i = pos_inf(pile_a);
		if (i < 3)
			rotate_a(pile_a);
		else
			rev_rotate_a(pile_a);
	}
	push_b(pile_a, pile_b);
	while (!elem_inf(pile_a, pile_a->premier->nombre))
	{
		i = pos_inf(pile_a);
		if (i < 3)
			rotate_a(pile_a);
		else
			rev_rotate_a(pile_a);
	}
	push_b(pile_a, pile_b);
	tri_3_elem(pile_a);
	push_a(pile_a, pile_b);
	push_a(pile_a, pile_b);
}

int	pos_inf(t_Pile *pile_a)
{
	int			*tab;
	int			i;
	int			j;
	int			x;

	i = 0;
	x = 0;
	tab = add_tab(pile_a);
	while (x != pile_a->size)
	{
		j = 0;
		while (j != pile_a->size)
		{
			if (tab[i] > tab[j])
				i = j;
			j++;
		}
		x++;
	}
	free(tab);
	return (i + 1);
}

int	elem_inf(t_Pile *pile_a, int first)
{
	t_Element	*temp;

	temp = pile_a->premier;
	while (temp->suivant)
	{
		if (temp->nombre < first)
			return (0);
		temp = temp->suivant;
	}
	return (1);
}
