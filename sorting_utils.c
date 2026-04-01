/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:56:58 by icoman            #+#    #+#             */
/*   Updated: 2026/04/01 21:58:47 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Aggiorna index e above_median dei nodi di uno stack. */
void	update_index(t_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
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
void	set_cheapest(t_node *stack)
{
	long	cheapest;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->is_cheapest = true;
}

/* Muove il nodo da spostare nell'altro stack in cima a quello stack
	in base alle funzioni passate (ra, rra oppure rb, rrb) */
void	prep_for_push(t_node **stack, t_node *new_top,
						void (*f_rr)(t_node **),
						void (*f_rrr)(t_node **))
{
	while (*stack != new_top)
	{
		if (new_top->above_median)
			f_rr(stack);
		else
			f_rrr(stack);
	}
}
