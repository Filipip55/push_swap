/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:20:36 by icoman            #+#    #+#             */
/*   Updated: 2026/03/31 19:37:04 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Inizializza lo stack A con i valori di argv
	e controlla la presenza di eventuali errori su quest'ultimi */
void	init_stack_a(t_node **st_a, char **argv)
{
	long n;
	int i;

	i = 1;
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

/* Serie di funzioni prelimiari sui nodi di a prima di essere spostati in b */
void	prepare_nodes_a(t_node *st_a, t_node *st_b)
{
	update_index(st_a);
	update_index(st_b);
	set_target_a(st_a, st_b);
	set_cost_a(st_a, st_b);
	set_cheapest(st_a);
}

/* Trova il target node per i nodi dello stack a
	Il target node in b e' quello col valore minore piu vicino
	a quello del nodo a corrente */
void	set_target_a(t_node *st_a, t_node *st_b)
{
	t_node	*curr_b;
	t_node	*target;
	long	min;

	while (st_a)
	{
		min = LONG_MIN;
		curr_b = st_b;
		while (curr_b)
		{
			if (curr_b->value < st_a->value
				&& curr_b->value > min)
			{
				min = curr_b->value;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (min == LONG_MIN)
			st_a->target = get_max_node(st_b);
		else
			st_a->target = target;
		st_a = st_a->next;
	}
}

/* Calcola il costo dello spostare i nodi di A in B tramite pb.
	Nell'effettivo calcola quante mosse servono per farlo arrivare alla cima di A
	tramite ra (se above_median == true) oppure rra (se above_median == false).
	Per uno spostamento corretto anche il target node deve esser in cima a B
	e si applica la stessa logica (stavolta con rb, rrb). */
void	set_cost_a(t_node *st_a, t_node *st_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(st_a);
	len_b = stack_len(st_b);
	while (st_a)
	{
		st_a->push_cost = st_a->index;
		if (!(st_a->above_median))
			st_a->push_cost = len_a - (st_a->index);
		if (st_a->target->above_median)
			st_a->push_cost += st_a->target->index;
		else
			st_a->push_cost += len_b - (st_a->target->index);
		st_a = st_a->next;
	}
}

/* Funzione helper per spostare il nodo in cima ad A in B, controlla
	se fare rr o rrr sia piu' economico  */
void	move_a_to_b(t_node **st_a, t_node **st_b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*st_a);
	if (cheapest->above_median && cheapest->target->above_median)
		keep_rotating(st_a, st_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		reverse_keep_rotating(st_a, st_b, cheapest);
	prep_for_push(st_a, cheapest, &ra, &rra);
	prep_for_push(st_b, cheapest->target, &rb, &rrb);
	pb(st_a, st_b);
}
