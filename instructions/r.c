/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:40:51 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/22 18:29:14 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_Pile *pile)
{
	t_Element	*temp;
	t_Element	*actuel;

	temp = pile->premier->suivant;
	actuel = pile->premier;
	while (actuel->suivant != NULL)
		actuel = actuel->suivant;
	actuel->suivant = NULL;
	pile->premier = actuel;
	pile->premier = temp;
}