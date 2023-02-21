/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:34 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/21 17:33:13 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void affiche_pile(t_Element **first)
{
	t_Element *e;

	e = (*first);
	while (e)
	{
		printf("%d\n", e->nombre);
		e = e->suivant;
 	}
}

int main(void)
{
	t_Pile *pile_a;
	
	pile_a = initialisation();
	insertion(pile_a, 3);
	insertion(pile_a, 7);
	insertion(pile_a, 5);
	insertion(pile_a, 9);
	affiche_pile(&pile_a->premier);
	swap_a(pile_a);
	printf("swap a\n");
	affiche_pile(&pile_a->premier);
	return (0);
}