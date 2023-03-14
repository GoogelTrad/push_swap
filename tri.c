/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:14:41 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/14 19:21:25 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri(t_Pile *pile_a, t_Pile *pile_b)
{
	t_Element	*tmp;
	t_Element	*actuel;

	actuel = pile_a->premier;
	while (!pile_trie(pile_a))
	{
		if ()
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

int	verif_pile(t_Pile *pile)
{
	if (pile->premier->suivant == NULL)
		return (1);
	return (0);
}

int	pile_trie(t_Pile *pile)
{
	t_Element *actu;
	
	actu = pile->premier;
	while (actu->nombre <= actu->suivant->nombre)
		actu = actu->suivant;
	if (actu->suivant)
		return (0);
	return (1);
}

t_Element	*elem_sup(t_Pile *pile)
{
	t_Element	*tmp;
	t_Element	*actuel;

	tmp = pile->premier;
	actuel = pile->premier;
	return (0);
}