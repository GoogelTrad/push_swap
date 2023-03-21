/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:17:43 by cmichez           #+#    #+#             */
/*   Updated: 2023/03/21 20:01:21 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_Element
{
	int					nombre;
	int					index;
	struct s_Element	*suivant;
}   t_Element;

typedef struct s_Pile
{
	t_Element	*premier;
	int			size;
}   t_Pile;

//init_list.c
t_Pile	*initialisation(void);
void	insertion(t_Pile *liste, int nombre);
void	swap_a(t_Pile *pile);
void	insertion_haut(t_Pile *pile, t_Element *element);
void	affiche_pile(t_Element **first);

//instructions

//swap
void	swap_a(t_Pile *pile);
void	swap_b(t_Pile *pile);
void	swap_ss(t_Pile *pile_a, t_Pile *pile_b);

//push
void	push_a(t_Pile *pile_a, t_Pile *pile_b);
void	push_b(t_Pile *pile_a, t_Pile *pile_b);

//rotate
void	rotate_a(t_Pile *pile);
void	rotate_b(t_Pile *pile);
void	rotate_r(t_Pile *pile_a, t_Pile *pile_b);

//reverse rotate
void    rev_rotate_a(t_Pile *pile);
void    rev_rotate_b(t_Pile *pile);
void    rev_rotate_r(t_Pile *pile_a, t_Pile *pile_b);

//utils
int		ft_atoi(char *nptr, int *y);
int		ft_strlen(char *str);
int		ft_isalpha(int c);
char	*ft_strdup(char *s);
int		*add_tab(t_Pile *pile_a);

//argument
t_Pile	*create_list(t_Pile *pile, int ac, char **av);
void	verif_str(char *str, t_Pile *pile);
int		verif_argument(int ac, char **av);
int		verif_doublons(t_Pile *pile);

//tri
void	tri(t_Pile *pile_a, t_Pile *pile_b);
int		pile_trie(t_Pile *pile);
int		rev_pile_trie(t_Pile *pile);
int		elem_sup(t_Element *actuel);
void	index_arg(t_Pile *pile);

//tri_a_3
void	tri_3_elem(t_Pile *pile_a);
void	tri_5_elem(t_Pile *pile_a, t_Pile *pile_b);
t_Element	*get_inf(t_Pile *a, int *i);

//tri_large
void	tri_large(t_Pile *pile_a, t_Pile *pile_b);
void	stacking_pile(t_Pile *pile_a, t_Pile *pile_b);
t_Element	*get_sup(t_Pile *a, int *i);
int		from_top(t_Pile *pile, int min, int max);
int		from_bot(t_Pile *pile, int min, int max);

#endif