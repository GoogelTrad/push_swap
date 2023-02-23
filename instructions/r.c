/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:40:51 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/23 19:05:26 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_Pile *pile)
{
	t_Element	*temp;
	t_Element	*element;
	t_Element	*actuel;

	temp = pile->premier->suivant;
	actuel = pile->premier;
	element = pile->premier;
	while (actuel->suivant != NULL)
		actuel = actuel->suivant;
	element->suivant = NULL;
	actuel->suivant = element;
	pile->premier = temp;
	
}

void	rotate_b(t_Pile *pile)
{
	t_Element	*temp;
	t_Element	*element;
	t_Element	*actuel;

	temp = pile->premier->suivant;
	actuel = pile->premier;
	element = pile->premier;
	while (actuel->suivant != NULL)
		actuel = actuel->suivant;
	element->suivant = NULL;
	actuel->suivant = element;
	pile->premier = temp;
	
}

void	rotate_r(t_Pile *pile_a, t_Pile *pile_b)
{
	rotate_a(pile_a);
	rotate_b(pile_b);
}