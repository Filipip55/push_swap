/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** swap: swaps the values of the first two nodes of stack.
** Does nothing if there are fewer than 2 elements.
*/
static void	swap(t_node **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

/*
** sa: swaps the top 2 elements of stack a, prints "sa".
*/
void	sa(t_node **stack)
{
	swap(stack);
	ft_putstr_fd("sa\n", 1);
}

/*
** sb: swaps the top 2 elements of stack b, prints "sb".
*/
void	sb(t_node **stack)
{
	swap(stack);
	ft_putstr_fd("sb\n", 1);
}

/*
** ss: swaps top 2 of both stacks simultaneously, prints "ss".
*/
void	ss(t_node **st_a, t_node **st_b)
{
	swap(st_a);
	swap(st_b);
	ft_putstr_fd("ss\n", 1);
}
