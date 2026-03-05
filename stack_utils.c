/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:22:58 by icoman            #+#    #+#             */
/*   Updated: 2026/03/05 18:22:48 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Controlla che i nodi dello stack siano ordinati in ordine crescente */
bool is_stack_sorted(node **stack)
{
	node *curr;

	if (!stack || !(*stack))
		return (true);
	curr = *stack;
	while (curr)
	{
		if (curr->next && curr->value > curr->next->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}

/* Restituisce il numero di nodi in uno stack */
int stack_len(node **stack)
{
	int len;
	node *curr;

	len = 0;
	curr = *stack;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

/* Aggiunge un nodo in cima allo stack */
void	add_node_front(node **stack, node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

/* Elimina un nodo */
void	del_node(node *old_node)
{
	if (!old_node)
		return ;
	free(old_node->above_half);
	free(old_node->cheapest);
	free(old_node->index);
	free(old_node->);
	free(old_node->above_half);
	free(old_node->above_half);
	free(old_node->above_half);
}
