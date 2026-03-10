/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:16:18 by icoman            #+#    #+#             */
/*   Updated: 2026/03/10 21:13:55 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  Crea un nuovo nodo e lo mette nell'ultima posizione (coda).
	Se lo stack e' vuoto allora lo mette in testa */
static void add_node_back(node **stack, int n)
{
	node	*new_node;
	node	*last_node;

	if (!stack)
		return (free(stack), NULL);
	new_node = malloc(sizeof(node));
	if (!new_node)
		return (free(new_node), NULL);
	new_node->next = NULL;
	new_node->value = n;
	if(!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = *stack;
		while (!last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

/* Inizializza lo stack A con i valori di argv
	e controlla eventuali errori su quest'ultimi */
void init_stack_a(node **st_a, char **argv)
{
	long n;
	int i;

	while (argv[i])
	{
		if (!check_sintax(argv[i]))
			free_errors(st_a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(st_a);
		if (is_duplicate(*st_a, (int)n))
			free_errors(st_a);
		add_node_back(st_a, (int)n);
		i++;
	}
}
