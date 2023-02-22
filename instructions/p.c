/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:25:42 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/22 15:39:41 by cmichez          ###   ########.fr       */
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
}