/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:34 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/14 17:22:05 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_Pile *pile_a;
	t_Pile *pile_b;
	pile_a = initialisation();
	pile_b = initialisation();
	pile_a = create_list(pile_a, argc, argv);
	tri(pile_a, pile_b);
	return (0);
}