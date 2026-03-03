/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:56:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/03 21:50:03 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(node **stack)
{
	node	*biggest;

	
}

void	sort_stacks(node **st_a, node **st_b)
{
	
}

node	*find_min(node **stack)
{
	node	*min;
	node	*curr;

	if (!stack || !(*stack))
		return (NULL);
	curr = *stack;
	min = *stack;
	while (!curr->next)
	{
		if (min->value > curr->value)
			min = curr;
		curr = curr->next;
	}
}

node	*find_max(node **stack)
{
	node	*max;
	node	*curr;

	if (!stack || !(*stack))
		return (NULL);
	curr = *stack;
	max = *stack;
	while (!curr->next)
	{
		if (max->value < curr->value)
			max = curr;
		curr = curr->next;
	}
}
