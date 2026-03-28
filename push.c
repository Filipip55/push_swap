/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:44:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/28 15:03:04 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **st_a, t_node **st_b)
{
	if (!st_a || !st_b || !(*st_b))
		return ;
	
}

/* push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty. */
void	pa(t_node **st_a, t_node **st_b)
{
	
	printf("pa\n");
}

/* (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty. */
void	pb(t_node **st_a, t_node **st_b)
{
	
	printf("pb\n");
}
