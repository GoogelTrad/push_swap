/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:40:22 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/21 18:38:39 by cmichez          ###   ########.fr       */
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
	t_Pile		*temp;
	
	nouveau = malloc(sizeof(nouveau));
	nouveau->nombre = nombre;
	temp = pile;
	while (temp->premier != NULL)
		temp->premier = temp->premier->suivant;
	temp->premier->suivant = nouveau;
}
