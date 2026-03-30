/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:58:38 by icoman            #+#    #+#             */
/*   Updated: 2026/03/28 17:36:36 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*st_a;
	t_node	*st_b;

	st_a = NULL;
	st_b = NULL;
	if (argc < 2)
		return (1);
	init_stack_a(&st_a, argv);
	if (!is_stack_sorted(st_a))
	{
		if (stack_len(st_a) == 2)
			sa(&st_a);
		else if (stack_len(st_a) == 3)
			sort_three(&st_a);
		else
			sort_stacks(&st_a, &st_b);
	}
	free(st_a);
	free(st_b);
	return (0);
}

/*  Crea un nuovo nodo e lo mette nell'ultima posizione (coda).
	Se lo stack e' vuoto allora lo mette in testa */
void	add_node_back(t_node **stack, int n)
{
	t_node	*new_node;
	t_node	*last_node;

	if (!stack)
		return (free(stack));
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		free_errors(stack);
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
