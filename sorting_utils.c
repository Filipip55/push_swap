/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:56:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/12 22:21:59 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Trova e restituisce il nodo più "economico" */
node	*get_cheapest(node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/* Trova e restituisce il nodo con il value piu piccolo. */
node	*find_min(node **stack)
{
	node	*min;
	node	*curr;

	if (!stack || !(*stack))
		return (NULL);
	curr = *stack;
	min = *stack;
	while (curr->next)
	{
		if (min->value > curr->value)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

/* Trova e restituisce il nodo con il value piu grande. */
node	*find_max(node **stack)
{
	node	*max;
	node	*curr;

	if (!stack || !(*stack))
		return (NULL);
	curr = *stack;
	max = *stack;
	while (curr->next)
	{
		if (max->value < curr->value)
			max = curr;
		curr = curr->next;
	}
	return (max);
}
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
