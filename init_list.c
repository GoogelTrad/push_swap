/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:40:22 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/22 00:07:28 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Pile	*initialisation(void)
{
	t_Pile		*pile;
	t_Element	*element;

	pile = malloc(sizeof(pile));
	element = malloc(sizeof(element));
	element->nombre = 0;
	element->suivant = NULL;
	pile->premier = element;
	return (pile);
}

void	insertion(t_Pile *pile, int nombre)
{
	t_Element	*nouveau;
	t_Element	*actuel;
	
	nouveau = malloc(sizeof(nouveau));
	nouveau->nombre = nombre;
	nouveau->suivant = NULL;
	if(pile->premier != NULL)
	{
		actuel = pile->premier;
		while (actuel->suivant != NULL)
			actuel = actuel->suivant;
		actuel->suivant = nouveau;
	}
	else
		pile->premier = nouveau;
}

void	insertion_haut(t_Pile *pile, t_Element *element)
{
	element->suivant = pile->premier;
	pile->premier = element;
}

void	affiche_pile(t_Element **first)
{
	t_Element	*e;

	e = (*first);
	while (e)
	{
		printf("%d\n", e->nombre);
		e = e->suivant;
 	}
}