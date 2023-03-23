/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:40:22 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/23 15:57:55 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Pile	*initialisation(void)
{
	t_Pile	*pile;

	pile = malloc(sizeof(pile));
	pile->premier = NULL;
	pile->size = 0;
	return (pile);
}

void	insertion(t_Pile *pile, int nombre)
{
	t_Element	*nouveau;
	t_Element	*actuel;

	nouveau = malloc(sizeof(t_Element));
	nouveau->nombre = nombre;
	nouveau->index = -1;
	nouveau->suivant = NULL;
	if (pile->premier != NULL)
	{
		actuel = pile->premier;
		while (actuel->suivant != NULL)
			actuel = actuel->suivant;
		actuel->suivant = nouveau;
	}
	else
		pile->premier = nouveau;
}

void	free_pile(t_Pile *a, t_Pile *b)
{
	t_Element	*e_a;
	t_Element	*tmp_a;

	tmp_a = a->premier;
	while (tmp_a)
	{
		e_a = tmp_a;
		tmp_a = tmp_a->suivant;
		free(e_a);
	}
	free(a);
	free(b);
}
