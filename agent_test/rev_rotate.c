/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rev_rotate: moves the last node of *stack to the top.
** last → first (circular shift down).
*/
static void	rev_rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

/*
** rra: reverse rotates stack a, prints "rra".
*/
void	rra(t_node **stack)
{
	rev_rotate(stack);
	ft_putstr_fd("rra\n", 1);
}

/*
** rrb: reverse rotates stack b, prints "rrb".
*/
void	rrb(t_node **stack)
{
	rev_rotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

/*
** rrr: reverse rotates both stacks simultaneously, prints "rrr".
*/
void	rrr(t_node **st_a, t_node **st_b)
{
	rev_rotate(st_a);
	rev_rotate(st_b);
	ft_putstr_fd("rrr\n", 1);
}
