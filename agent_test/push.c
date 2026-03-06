/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push: moves the top node of src to the top of dst.
** Unlinks node from src, then prepends it to dst.
*/
static void	push(t_node **dst, t_node **src)
{
	t_node	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dst;
	node->prev = NULL;
	if (*dst)
		(*dst)->prev = node;
	*dst = node;
}

/*
** pa: pushes top of b to top of a, prints "pa".
*/
void	pa(t_node **st_a, t_node **st_b)
{
	push(st_a, st_b);
	ft_putstr_fd("pa\n", 1);
}

/*
** pb: pushes top of a to top of b, prints "pb".
*/
void	pb(t_node **st_a, t_node **st_b)
{
	push(st_b, st_a);
	ft_putstr_fd("pb\n", 1);
}
