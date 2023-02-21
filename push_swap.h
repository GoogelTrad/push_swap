/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:17:43 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/22 00:07:51 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_Element
{
	int nombre;
	struct s_Element *suivant;
}   t_Element;

typedef struct s_Pile
{
	t_Element *premier;
}   t_Pile;

//init_list.c
t_Pile	*initialisation(void);
void	insertion(t_Pile *liste, int nombre);
void	swap_a(t_Pile *pile);
void	insertion_haut(t_Pile *pile, t_Element *element);
void	affiche_pile(t_Element **first);

//instructions
void	swap_a(t_Pile *pile);
void	swap_b(t_Pile *pile);
void	swap_ss(t_Pile *pile_a, t_Pile *pile_b);

#endif