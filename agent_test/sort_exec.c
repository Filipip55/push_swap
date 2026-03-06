/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** find_target_a: sets node_b->target to the best destination in st_a.
** Target = smallest value in a that is greater than node_b->value.
** If none exists (node_b is larger than all of a), target = min of a.
*/
void	find_target_a(t_node *node_b, t_node *st_a)
{
	t_node	*candidate;
	t_node	*current;

	candidate = NULL;
	current = st_a;
	while (current)
	{
		if (current->value > node_b->value)
		{
			if (!candidate || current->value < candidate->value)
				candidate = current;
		}
		current = current->next;
	}
	if (!candidate)
		candidate = find_min(st_a);
	node_b->target = candidate;
}

/*
** rotate_each: finishes positioning after simultaneous phase.
** Rotates st_a until cheapest is on top, then st_b until target is on top.
*/
static void	rotate_each(t_node **st_a, t_node **st_b, t_node *cheapest)
{
	set_above_half(*st_a, stack_len(*st_a));
	set_above_half(*st_b, stack_len(*st_b));
	while (*st_a != cheapest)
	{
		if (cheapest->above_half)
			ra(st_a);
		else
			rra(st_a);
	}
	while (*st_b != cheapest->target)
	{
		if (cheapest->target->above_half)
			rb(st_b);
		else
			rrb(st_b);
	}
}

/*
** rotate_both: brings cheapest node in a and its target in b to the top,
** using simultaneous rr/rrr ONLY when both are in the same half.
** After simultaneous phase, finishes with individual rotations.
*/
void	rotate_both(t_node **st_a, t_node **st_b, t_node *cheapest)
{
	if (cheapest->above_half && cheapest->target->above_half)
	{
		while (*st_a != cheapest && *st_b != cheapest->target)
			rr(st_a, st_b);
	}
	else if (!cheapest->above_half && !cheapest->target->above_half)
	{
		while (*st_a != cheapest && *st_b != cheapest->target)
			rrr(st_a, st_b);
	}
	rotate_each(st_a, st_b, cheapest);
}

/*
** move_a_to_b: finds the cheapest node in a, rotates both stacks to align it
** with its target in b, then pushes it (pb).
** When b is empty, we just push the top of a directly (no target needed).
*/
void	move_a_to_b(t_node **st_a, t_node **st_b)
{
	t_node	*cheapest;

	if (!*st_b)
	{
		pb(st_a, st_b);
		return ;
	}
	prepare_nodes_a(*st_a, *st_b);
	cheapest = find_cheapest(*st_a);
	rotate_both(st_a, st_b, cheapest);
	pb(st_a, st_b);
}

/*
** push_b_to_a: pushes every node from b back to a in sorted order.
** For each top of b, find its target in a, rotate a so target is on top, pa.
*/
void	push_b_to_a(t_node **st_a, t_node **st_b)
{
	int	len_a;

	while (*st_b)
	{
		find_target_a(*st_b, *st_a);
		len_a = stack_len(*st_a);
		set_above_half(*st_a, len_a);
		while (*st_a != (*st_b)->target)
		{
			if ((*st_b)->target->above_half)
				ra(st_a);
			else
				rra(st_a);
		}
		pa(st_a, st_b);
	}
}

/*
** sort_stacks: main Turk algorithm entry point.
** Phase 1 – push from a to b until 3 remain.
** Phase 2 – sort those 3 in a.
** Phase 3 – push all of b back to a.
** Final   – rotate a so the minimum is on top.
*/
void	sort_stacks(t_node **st_a, t_node **st_b)
{
	t_node	*min;
	int		len_a;

	len_a = stack_len(*st_a);
	if (len_a == 2)
	{
		sa(st_a);
		return ;
	}
	while (stack_len(*st_a) > 3)
		move_a_to_b(st_a, st_b);
	sort_three(st_a);
	push_b_to_a(st_a, st_b);
	min = find_min(*st_a);
	len_a = stack_len(*st_a);
	set_above_half(*st_a, len_a);
	while (*st_a != min)
	{
		if (min->above_half)
			ra(st_a);
		else
			rra(st_a);
	}
}
