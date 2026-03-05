/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:44:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/05 18:08:20 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(node **st_a, node **st_b)
{
	if (!st_a || !st_b || !(*st_b))
		return ;
	add_node_front(st_a, *st_b);
	del_node(*st_b);
}

void	pb(node **st_a, node **st_b)
{
	if (!st_b || !st_a || !(*st_a))
		return ;
	add_node_front(st_b, *st_a);
	del_node(*st_a);
}
