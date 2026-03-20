/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:32:17 by icoman            #+#    #+#             */
/*   Updated: 2026/03/20 19:33:57 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Serie di funzioni prelimiari sui nodi di b prima di essere spostati in a */
void	prepare_nodes_a(node *st_a, node *st_b)
{
	update_index(st_a);
	update_index(st_b);
	set_target_b(st_a, st_b);
}

void	set_target_b(node *st_a, node *st_b)
{
	node	*curr_a;
	node	*target;
	long	max;

	while (st_b)
	{
		max = LONG_MAX;
		curr_a = st_a;
		while (curr_a)
		{
			if (curr_a->value > st_b->value
				&& curr_a->value < max)
			{
				max = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (max == LONG_MAX)
			st_b->target = find_min(st_a);
		else
			st_b->target = target;
		st_b = st_b->next;
	}
}

static void	move_b_to_a(node **st_a, node **st_b)
{
	prep_for_push(st_a, (*st_b)->target, &ra, &rra);
	pa(st_a, st_b, true);
}
