/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** set_above_half: for every node in stack, sets above_half = true when the
** node's 0-indexed position from top is <= len / 2.
*/
void	set_above_half(t_node *stack, int len)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (pos <= len / 2)
			stack->above_half = true;
		else
			stack->above_half = false;
		pos++;
		stack = stack->next;
	}
}

/*
** find_target_b: sets node_a->target to the best destination in st_b.
** Target = largest value in b that is still smaller than node_a->value.
** If none exists (node_a is smaller than all of b), target = max of b.
*/
void	find_target_b(t_node *node_a, t_node *st_b)
{
	t_node	*candidate;
	t_node	*current;

	candidate = NULL;
	current = st_b;
	while (current)
	{
		if (current->value < node_a->value)
		{
			if (!candidate || current->value > candidate->value)
				candidate = current;
		}
		current = current->next;
	}
	if (!candidate)
		candidate = find_max(st_b);
	node_a->target = candidate;
}

/*
** set_node_cost: computes the total push cost for node in st_a.
** pos_a = 0-indexed position of node from top of stack a.
** len_a is derived from pos_a + remaining list length (no extra param needed).
** Simultaneous ops (rr/rrr) reduce cost when both rotate in same direction.
*/
void	set_node_cost(t_node *node, t_node *st_b, int pos_a, int len_b)
{
	int		cost_a;
	int		cost_b;
	int		len_a;
	int		pos_b;

	len_a = pos_a + stack_len(node);
	pos_b = 0;
	while (st_b != node->target)
	{
		pos_b++;
		st_b = st_b->next;
	}
	if (node->above_half)
		cost_a = pos_a;
	else
		cost_a = len_a - pos_a;
	if (node->target->above_half)
		cost_b = pos_b;
	else
		cost_b = len_b - pos_b;
	if (node->above_half == node->target->above_half)
	{
		if (cost_a > cost_b)
			node->push_cost = cost_a;
		else
			node->push_cost = cost_b;
	}
	else
		node->push_cost = cost_a + cost_b;
}

/*
** prepare_nodes_a: for every node in st_a, sets above_half, finds its target
** in b, and computes its push_cost. Called once before each push from a to b.
*/
void	prepare_nodes_a(t_node *st_a, t_node *st_b)
{
	int		len_b;
	int		pos;
	t_node	*current;

	len_b = stack_len(st_b);
	set_above_half(st_a, stack_len(st_a));
	set_above_half(st_b, len_b);
	pos = 0;
	current = st_a;
	while (current)
	{
		find_target_b(current, st_b);
		set_node_cost(current, st_b, pos, len_b);
		pos++;
		current = current->next;
	}
}

/*
** find_cheapest: returns the node in st_a with the minimum push_cost.
** Also marks that node's cheapest flag as true (resets others to false).
*/
t_node	*find_cheapest(t_node *st_a)
{
	t_node	*cheapest;
	t_node	*current;

	cheapest = st_a;
	current = st_a;
	while (current)
	{
		current->cheapest = false;
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	cheapest->cheapest = true;
	return (cheapest);
}
