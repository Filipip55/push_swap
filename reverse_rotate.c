/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:46:38 by icoman            #+#    #+#             */
/*   Updated: 2026/04/01 21:48:49 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

/* Sposta gli elementi verso il basso, l'ultimo diventa il primo */
void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **st_a)
{
	reverse_rotate(st_a);
	ft_printf("rra\n", false);
}

void	rrb(t_node **st_b)
{
	reverse_rotate(st_b);
	ft_printf("rrb\n", false);
}

void	rrr(t_node **st_a, t_node **st_b)
{
	reverse_rotate(st_a);
	reverse_rotate(st_b);
	ft_printf("rrr\n", false);
}

/* Esegue rrr finche' il nodo piu' economico da spostare di A e' in cima
	e finche' il suo target node in B non e' in cima
	da chiamare solo se entrambi i nodi in questione hanno 
	above_median settato a false */
void	reverse_keep_rotating(t_node **st_a, t_node **st_b, t_node *cheapest)
{
	while (*st_a != cheapest && *st_b != cheapest->target)
		rrr(st_a, st_b);
	update_index(*st_a);
	update_index(*st_b);
}
