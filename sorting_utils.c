/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:56:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/15 13:52:02 by icoman           ###   ########.fr       */
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
