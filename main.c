/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:34 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/23 16:03:22 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Pile	*pile_a;
	t_Pile	*pile_b;

	pile_a = initialisation();
	pile_b = initialisation();
	if (argc > 1)
	{
		pile_a = create_list(pile_a, pile_b, argc, argv);
		if (!pile_a->premier)
		{
			free_pile(pile_a, pile_b);
			return (0);
		}
		index_arg(pile_a);
		tri(pile_a, pile_b);
	}
	free_pile(pile_a, pile_b);
	return (0);
}
