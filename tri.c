/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:14:41 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/02 17:19:57 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri(t_Pile *pile_a, t_Pile *pile_b, int size)
{
	while (size)
	{
		printf("pile a\n");
		affiche_pile(&pile_a->premier);
		printf("pile b\n");
		affiche_pile(&pile_b->premier);
		printf("tri\n");
		swap_premier(pile_a, pile_b);
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