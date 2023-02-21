/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:07:48 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/21 18:23:50 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_Pile *pile)
{
	t_Element	*temp;

	temp = pile->premier->suivant;
	pile->premier->suivant = pile->premier->suivant->suivant;
	temp->suivant = pile->premier;
	pile->premier = temp;
}

void	swap_b(t_Pile *pile)
{
	t_Element	*temp;

	temp = pile->premier->suivant;
	pile->premier->suivant = pile->premier->suivant->suivant;
	temp->suivant = pile->premier;
	pile->premier = temp;
}

void	swap_ss(t_Pile *pile_a, t_Pile *pile_b)
{
	swap_a(pile_a);
	swap_b(pile_b);
}