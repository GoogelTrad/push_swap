/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:14:41 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/03 16:45:30 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri(t_Pile *pile_a, t_Pile *pile_b)
{
	while (is_triee(pile_a) && pile_b->premier == NULL)
	{
		while (pile_a->size > 1)
		{
			printf("tri a\n");
			swap_premier(pile_a, pile_b);
			rotate_a(pile_a);
		}
		while (pile_b->size > 1)
		{
			printf("tri b\n");
			swap_premier(pile_b, pile_a);
			rotate_b(pile_b);
		}
	}
}

void	swap_premier(t_Pile *pile_a, t_Pile *pile_b)
{
	if (pile_a->premier->nombre > pile_a->premier->suivant->nombre)
	{
		swap_a(pile_a);
		push_b(pile_a, pile_b);
	}
	else
		push_b(pile_a, pile_b);
}

int	is_triee(t_Pile *pile_a)
{
	t_Element *actuel;

	actuel = pile_a->premier;
	while (actuel->nombre < actuel->suivant->nombre)
		actuel = actuel->suivant;
	if (!(actuel->nombre < actuel->suivant->nombre))
		return (1);
	affiche_pile(&pile_a->premier);
	return (0);
}