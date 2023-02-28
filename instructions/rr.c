/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:53:13 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/23 18:53:13 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rev_rotate_a(t_Pile *pile)
{
    t_Element   *temp;
    t_Element   *actuel;

    actuel = pile->premier;
    while (actuel->suivant->suivant != NULL)
        actuel = actuel->suivant;
    temp = actuel->suivant;
    temp->suivant = pile->premier;
    pile->premier = temp;
    actuel->suivant = NULL;
}

void    rev_rotate_b(t_Pile *pile)
{
    t_Element   *temp;
    t_Element   *actuel;

    actuel = pile->premier;
    while (actuel->suivant->suivant != NULL)
        actuel = actuel->suivant;
    temp = actuel->suivant;
    temp->suivant = pile->premier;
    pile->premier = temp;
    actuel->suivant = NULL;
}

void    rev_rotate_r(t_Pile *pile_a, t_Pile *pile_b)
{
    rev_rotate_a(pile_a);
    rev_rotate_b(pile_b);
}