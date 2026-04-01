/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:44:58 by icoman            #+#    #+#             */
/*   Updated: 2026/04/01 21:51:46 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* dest = puntatore allo stack di destinazione
	src = puntatore allo stack di origine (da cui togliamo il nodo) */
void	push(t_node **dest, t_node **src)
{
	t_node	*node_to_push;

	if (!dest || !src || !(*src))
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	node_to_push->next = *dest;
	*dest = node_to_push;
}

/* Prende il primo elemento in cima a B e lo mette in cima ad A. */
void	pa(t_node **st_a, t_node **st_b)
{
	push(st_a, st_b);
	ft_printf("pa\n", false);
}

/* Prende il primo elemento in cima ad A e lo mette in cima a B. */
void	pb(t_node **st_a, t_node **st_b)
{
	push(st_b, st_a);
	ft_printf("pb\n", false);
}
