/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:22:15 by icoman            #+#    #+#             */
/*   Updated: 2026/03/05 21:35:50 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(node **st_a, node **st_b)
{
	int	len_a;

	len_a = stack_len(st_a);
	if (len_a-- > 3 && !is_stack_sorted(st_a))
		pb(st_a, st_b);
	if (len_a-- > 3 && !is_stack_sorted(st_a))
		pb(st_a, st_b);
	while (len_a-- > 3 && !is_stack_sorted(st_a))
	{
		prepare_nodes_a(st_a, st_b);
		move_a_to_b(st_a, st_b);
	}
	sort_three(st_a);
}
