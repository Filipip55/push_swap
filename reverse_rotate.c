/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:46:38 by icoman            #+#    #+#             */
/*   Updated: 2026/03/28 15:03:20 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **stack)
{
	
}

void	rra(t_node **st_a)
{
	reverse_rotate(st_a);
	printf("rra\n");
}

void	rrb(t_node **st_b)
{
	reverse_rotate(st_b);
	printf("rrb\n");
}

void	rrr(t_node **st_a, t_node **st_b)
{
	reverse_rotate(st_a);
	reverse_rotate(st_b);
	printf("rrr\n");
}

/* Esegue rrr finche' il nodo piu' economico da spostare di A e' in cima
	e finche' il suo target node in B non e' in cima
	da chiamare solo se entrambi i nodi in questione hanno above_median settato a false */
void	reverse_keep_rotating(t_node **st_a, t_node **st_b, t_node *cheapest)
{
	while (*st_a != cheapest && *st_b != cheapest->target)
		rrr(st_a, st_b);
	update_index(*st_a);
	update_index(*st_b);
}
