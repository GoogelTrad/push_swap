/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:25:42 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/03 16:38:36 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_Pile *pile_a, t_Pile *pile_b)
{
	t_Element	*nouveau;
	t_Element	*temp;
	
	if (pile_b->premier == NULL)
        return ;
	temp = pile_b->premier->suivant;
	nouveau = pile_b->premier;
	nouveau->suivant = pile_a->premier;
	pile_a->premier = nouveau;
	pile_b->premier = temp;
	pile_a->size++;
	pile_b->size--;
}

void	push_b(t_Pile *pile_a, t_Pile *pile_b)
{
	t_Element	*nouveau;
	t_Element	*temp;
	
	if (pile_a->premier == NULL)
        return ;
	temp = pile_a->premier->suivant;
	nouveau = pile_a->premier;
	nouveau->suivant = pile_b->premier;
	pile_b->premier = nouveau;
	pile_a->premier = temp;
	pile_a->size--;
	pile_b->size++;
}