/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:34 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/22 00:07:38 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	t_Pile *pile_a;
	t_Pile *pile_b;
	
	pile_a = initialisation();
	pile_b = initialisation();
	insertion(pile_a, 3);
	insertion(pile_b, 7);
	insertion(pile_a, 7);
	insertion(pile_b, 5);
	insertion(pile_a, 9);
	printf("pile a\n");
	affiche_pile(&pile_a->premier);
	printf("pile b\n");
	affiche_pile(&pile_b->premier);
	swap_a(pile_a);
	printf("swap a\n");
	affiche_pile(&pile_a->premier);
	swap_b(pile_b);
	printf("swap b\n");
	affiche_pile(&pile_b->premier);
	return (0);
}