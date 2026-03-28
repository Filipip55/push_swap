/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:22:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/28 15:06:50 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Controlla che i nodi dello stack siano ordinati in ordine crescente */
bool is_stack_sorted(t_node **stack)
{
	t_node *curr;

	if (!stack || !(*stack))
		return (true);
	curr = *stack;
	while (curr)
	{
		if (curr->next && curr->value > curr->next->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}

/* Restituisce il numero di nodi in uno stack */
int stack_len(t_node **stack)
{
	int len;
	t_node *curr;

	len = 0;
	curr = *stack;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

/* Trova e restituisce il nodo più "economico" */
t_node	*get_cheapest(t_node *stack)
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
t_node	*get_min_node(t_node **stack)
{
	t_node	*min;
	t_node	*curr;

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
t_node	*get_max_node(t_node **stack)
{
	t_node	*max;
	t_node	*curr;

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
