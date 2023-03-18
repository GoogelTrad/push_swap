/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:14:41 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/18 01:18:04 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri(t_Pile *pile_a, t_Pile *pile_b)
{
	if (pile_a->size == 2)
	{
		if (pile_a->premier->nombre > pile_a->premier->suivant->nombre)
			swap_a(pile_a);
	}
	else if (pile_a->size == 3)
		tri_3_elem(pile_a);
	else if (pile_a->size == 4)
		tri_4_elem(pile_a, pile_b);
	else if (pile_a->size == 5)
		tri_5_elem(pile_a, pile_b);
	printf("pile a\n");
	affiche_pile(&pile_a->premier);
	printf("pile b\n");
	affiche_pile(&pile_b->premier);
}

int	rev_pile_trie(t_Pile *pile)
{
	t_Element *tmp;

	tmp = pile->premier;
	while (tmp->suivant)
	{
		if (tmp->nombre < tmp->suivant->nombre)
			return (0);
		tmp = tmp->suivant;
	}
	return (1);
}

int	pile_trie(t_Pile *pile)
{
	t_Element *tmp;

	tmp = pile->premier;
	while (tmp->suivant)
	{
		if (tmp->nombre > tmp->suivant->nombre)
			return (0);
		tmp = tmp->suivant;
	}
	return (1);
}


int	elem_sup(t_Element *actuel)
{
	while(actuel->nombre > actuel->suivant->nombre)
		actuel = actuel->suivant;
	if (actuel->suivant)
		return (1);
	return (0);
}