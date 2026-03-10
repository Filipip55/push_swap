/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:08:57 by icoman            #+#    #+#             */
/*   Updated: 2026/03/10 02:05:45 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sposta gli elementi verso 'l'alto', quindi il primo diventa l'ultimo */
void	rotate(node **stack)
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

void	ra(node **stack, bool to_print)
{
	rotate(stack);
	if (to_print)
		return (ft_printf("ra\n"));
}

void	rb(node **stack, bool to_print)
{
	rotate(stack);
	if (to_print)
		return (ft_printf("rb\n"));
}

void	rr(node **st_a, node **st_b, bool to_print)
{
	rotate(st_a);
	rotate(st_b);
	if (to_print)
		return (ft_printf("rr\n"));
}
