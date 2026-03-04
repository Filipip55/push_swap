/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:22:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/04 12:31:03 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



bool is_stack_sorted(node **stack)
{
	node *curr;

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

int stack_len(node **stack)
{
	int len;
	node *curr;

	len = 0;
	curr = *stack;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}