/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:56:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/16 22:29:25 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Aggiorna index e above_median dei nodi di uno stack. */
void	update_index(node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i++ <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
	}
}
/* Controlla quale nodo ha il push_cost minore e lo imposta come quello
	più "economico" da spostare nell'altro stack. */
void	set_is_cheapest(node *stack)
{
	long	cheapest;
	node	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MIN;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = true;
}

/* Muove il nodo da spostare nell'altro stack in cima a quello stack
	in base alle funzioni passate (ra, rra oppure rb, rrb) */
void	prep_for_push(node **stack, node *new_top,
						void (*f_rr)(node **, bool),
						void (*f_rrr)(node **, bool))
{
	while (*stack != new_top)
	{
		if (new_top->above_median)
			f_rr(stack, true);
		else
			f_rrr(stack, true);
	}
}
