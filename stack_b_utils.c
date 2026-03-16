/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:32:17 by icoman            #+#    #+#             */
/*   Updated: 2026/03/16 22:35:03 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Serie di funzioni prelimiari sui nodi di b prima di essere spostati in a */
void	prepare_nodes_a(node *st_a, node *st_b)
{
	update_index(st_a);
	update_index(st_b);
	set_target_b(st_a, st_b);
}

void	set_target_b(node *st_a, node *st_b)
{

}
