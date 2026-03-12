/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:22:15 by icoman            #+#    #+#             */
/*   Updated: 2026/03/12 22:22:08 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Ordina lo stack quando ha solo 3 nodi
	- se il piu grande e' in cima, ra (3 2 1 -> 2 1 3)
	- se il secondo e' il piu grande, rra (2 3 1 -> 1 2 3)
	- infine controlla se il primo e' maggiore del secondo
		per eseguire sa (2 1 3 -> 1 2 3)
	 */
void	sort_three(node **stack)
{
	node	*biggest;

	biggest = find_max(stack);
	if (biggest == *stack)
		ra(stack, true);
	else if ((*stack)->next == biggest)
		rra(stack, true);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, true);
}

void	sort_stacks(node **st_a, node **st_b)
{
	int	len_a;

	len_a = stack_len(st_a);
	if (len_a-- > 3 && !is_stack_sorted(st_a))
		pb(st_a, st_b, true);
	if (len_a-- > 3 && !is_stack_sorted(st_a))
		pb(st_a, st_b, true);
	while (len_a-- > 3 && !is_stack_sorted(st_a))
	{
		prepare_nodes_a(st_a, st_b);
		move_a_to_b(st_a, st_b);
	}
	sort_three(st_a);
	while (st_b)
	{
		prepare_nodes_b(st_a, st_a);
		move_b_to_a(st_a, st_b);
	}
	update_index(*st_a);
	move_min_on_top(st_a);
}

void	move_a_to_b(node *st_a, node *st_b)
{
	
}
