/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:46:38 by icoman            #+#    #+#             */
/*   Updated: 2026/03/16 21:04:12 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both(node **st_a, node **st_b, node *cheapest)
{
	while (*st_a != cheapest && *st_b != cheapest->target)
		rrr(st_a, st_b, true);
	update_index(*st_a);
	update_index(*st_b);
}
