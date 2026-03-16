/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:08:57 by icoman            #+#    #+#             */
/*   Updated: 2026/03/16 21:03:30 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sposta gli elementi verso 'l'alto', quindi il primo diventa l'ultimo */
void	rotate(node **stack)
{
	node	*first;
	node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(node **stack, bool to_print)
{
	rotate(stack);
	if (to_print)
		return (ft_printf("ra\n"));
}

void	rb(node **stack, bool to_print)
{
	rotate(stack);
	if (to_print)
		return (ft_printf("rb\n"));
}

void	rr(node **st_a, node **st_b, bool to_print)
{
	rotate(st_a);
	rotate(st_b);
	if (to_print)
		return (ft_printf("rr\n"));
}
/* Esegue rr finche' il nodo piu' economico da spostare di A e' in cima
	e finche' il suo target node in B non e' in cima
	da chiamare solo se entrambi i nodi in questione hanno above_median settato a true */
void	rotate_both(node **st_a, node **st_b, node *cheapest)
{
	while (*st_a != cheapest && *st_b != cheapest->target)
		rr(st_a, st_b, true);
	update_index(*st_a);
	update_index(*st_b);
}
