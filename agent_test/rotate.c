/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rotate: moves the first node of *stack to the bottom.
** first → last (circular shift up).
*/
static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

/*
** ra: rotates stack a upward, prints "ra".
*/
void	ra(t_node **stack)
{
	rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

/*
** rb: rotates stack b upward, prints "rb".
*/
void	rb(t_node **stack)
{
	rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

/*
** rr: rotates both stacks simultaneously, prints "rr".
*/
void	rr(t_node **st_a, t_node **st_b)
{
	rotate(st_a);
	rotate(st_b);
	ft_putstr_fd("rr\n", 1);
}
