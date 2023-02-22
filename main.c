/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:34 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/22 18:18:21 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	t_Pile *pile_a;
	t_Pile *pile_b;
	
	pile_a = initialisation();
	pile_b = initialisation();
	insertion(pile_a, 1);
	insertion(pile_b, 4);
	insertion(pile_a, 2);
	insertion(pile_b, 5);
	insertion(pile_a, 3);
	printf("pile a\n");
	affiche_pile(&pile_a->premier);
	printf("rotate a\n");
	rotate_a(pile_a);
	printf("pile a\n");
	affiche_pile(&pile_a->premier);
	return (0);
}