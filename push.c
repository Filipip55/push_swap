/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:44:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/05 21:31:41 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty. */
void	pa(node **st_a, node **st_b)
{
	if (!st_a || !st_b || !(*st_b))
		return ;
	add_node_front(st_a, *st_b);
	del_node(*st_b);
}

/* (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty. */
void	pb(node **st_a, node **st_b)
{
	if (!st_b || !st_a || !(*st_a))
		return ;
	add_node_front(st_b, *st_a);
	del_node(*st_a);
}
