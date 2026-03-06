/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** sort_three: sorts exactly 3 elements in stack a.
**
** Strategy:
**  1. Find the max. If it is at position 0 (top) → ra brings it to bottom.
**     Else if it is at position 1 (middle) → rra brings it to bottom.
**  2. After the max is at the bottom, if the remaining top two are out of
**     order → sa fixes them.
*/
void	sort_three(t_node **stack)
{
	t_node	*max;

	max = find_max(*stack);
	if (max == *stack)
		ra(stack);
	else if (max == (*stack)->next)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}
