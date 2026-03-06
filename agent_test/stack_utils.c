/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** stack_len: returns the number of nodes in stack.
*/
int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

/*
** find_last: returns a pointer to the last node in stack.
*/
t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*
** is_stack_sorted: returns 1 if stack is sorted ascending, 0 otherwise.
*/
int	is_stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
** find_min: returns pointer to the node with the smallest value.
*/
t_node	*find_min(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

/*
** find_max: returns pointer to the node with the largest value.
*/
t_node	*find_max(t_node *stack)
{
	t_node	*max;

	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

/*
** del_stack: frees every node in *stack and sets *stack to NULL.
*/
void	del_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
