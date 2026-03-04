/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:56:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/04 12:32:58 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Ordina lo stack quando ha solo 3 nodi
	 */
void	sort_three(node **stack)
{
	node	*biggest;

	biggest = find_max(stack);
	if (biggest == *stack)
		ra(stack, false);
	else if ((*stack)->next == biggest)
		rra(stack, false);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, false);
}

/* Trova e restituisce il nodo con il value piu piccolo */
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

/* Trova e restituisce il nodo con il value piu grande */
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
