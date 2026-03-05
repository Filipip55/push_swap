/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:08:57 by icoman            #+#    #+#             */
/*   Updated: 2026/03/05 18:20:48 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(node **stack)
{
	node	*first;
	node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	rb(node **stack)
{
	ra(stack);
}

void	rr(node **st_a, node **st_b)
{
	ra(st_a);
	ra(st_b);
}
