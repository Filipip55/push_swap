/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:22:15 by icoman            #+#    #+#             */
/*   Updated: 2026/04/08 14:52:21 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Ordina lo stack quando ha solo 3 nodi
	- se il piu grande e' in cima, ra (3 2 1 -> 2 1 3)
	- se il secondo e' il piu grande, rra (2 3 1 -> 1 2 3)
	- infine controlla se il primo e' maggiore del secondo
		per eseguire sa (2 1 3 -> 1 2 3)
	 */
void	sort_three(t_node **stack)
{
	t_node	*biggest;

	biggest = get_max_node(*stack);
	if (biggest == *stack)
		ra(stack, true);
	else if ((*stack)->next == biggest)
		rra(stack, true);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, true);
}

/* pb due volte per poter calcolare il costo dello spostamento in B,
	altrimenti il calcolo del costo non ha nulla su cui basarsi inizialmente */
void	sort_stacks(t_node **st_a, t_node **st_b)
{
	int	len_a;

	len_a = stack_len(*st_a);
	if (len_a-- > 3 && !is_stack_sorted(*st_a))
		pb(st_a, st_b, true);
	if (len_a-- > 3 && !is_stack_sorted(*st_a))
		pb(st_a, st_b, true);
	while (len_a-- > 3 && !is_stack_sorted(*st_a))
	{
		prepare_nodes_a(*st_a, *st_b);
		move_a_to_b(st_a, st_b);
	}
	sort_three(st_a);
	while (*st_b)
	{
		prepare_nodes_b(*st_a, *st_b);
		move_b_to_a(st_a, st_b);
	}
	update_index(*st_a);
	move_min_on_top(st_a);
}

/* Sposta il nodo col valore minimo in testa allo stack A
	e' l'ultimo passaggio dell'ordinamento */
void	move_min_on_top(t_node **st_a)
{
	t_node	*min;

	min = get_min_node(*st_a);
	while (*st_a != min)
	{
		if (min->above_median)
			ra(st_a, true);
		else
			rra(st_a, true);
		min = get_min_node(*st_a);
	}
}
