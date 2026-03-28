/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:16:18 by icoman            #+#    #+#             */
/*   Updated: 2026/03/28 15:02:48 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  Crea un nuovo nodo e lo mette nell'ultima posizione (coda).
	Se lo stack e' vuoto allora lo mette in testa */
static void	add_node_back(t_node **stack, int n)
{
	t_node	*new_node;
	t_node	*last_node;

	if (!stack)
		return (free(stack));
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (free(new_node), NULL);
	new_node->next = NULL;
	new_node->value = n;
	if(!(*stack))
		*stack = new_node;
	else
	{
		last_node = *stack;
		while (!last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

bool check_sintax(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < 48 || arg[i] > 57)
			return (write(2, "Error\n", 6), false);
	}
	return (true);
}
