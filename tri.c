/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:14:41 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/08 16:15:10 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri(t_Pile *pile_a, t_Pile *pile_b)
{
	while (!pile_trie(pile_a))
	{
		while (verif_pile(pile_a))
			swap_premier(pile_a, pile_b);
		printf("pile b\n");
		affiche_pile(&pile_a->premier);
		printf("pile b\n");
		affiche_pile(&pile_b->premier);
		while (verif_pile(pile_b))
			swap_premier(pile_b, pile_a);
		printf("pile b\n");
		affiche_pile(&pile_a->premier);
		printf("pile b\n");
		affiche_pile(&pile_b->premier);		
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