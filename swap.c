/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:04:52 by icoman            #+#    #+#             */
/*   Updated: 2026/03/10 02:07:19 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Scambia di posizione i primi elementi di uno stack */
void	swap(node **stack)
{
	node	*first;
	node	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(node **stack, bool to_print)
{
	swap(stack);
	if (to_print)
		return (ft_printf("sa\n"));
}

void	sb(node **stack, bool to_print)
{
	swap(stack);
	if (to_print)
		return (ft_printf("sb\n"));
}

void	ss(node **st_a, node **st_b, bool to_print)
{
	swap(st_a);
	swap(st_b);
	if (to_print)
		return (ft_printf("ss\n"));
}
