/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:49:29 by icoman            #+#    #+#             */
/*   Updated: 2026/03/28 15:18:16 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include <stdarg.h>
# include "libft/libft.h"

/*  value -> rappresenta l'intero
	index -> l'id univoco del nodo 
			(utile per calcolare il costo di spostamento da uno stack all'altro)
	push_cost -> il costo per spostare il nodo
	is_cheapest -> true se ha il costo piu basso
	above_half -> true se il nodo si trova nella 
				prima meta dello stack 
	target -> nodo a cui puntare nello spostamento
	next e prev -> puntano al nodo successivo e precedente */
typedef struct s_node
{
    int             value;
    int             index;
    int             push_cost;
    bool            is_cheapest;
    bool            above_median;
    struct s_node   *target;
    struct s_node   *next;
}   t_node;

static void	add_node_back(t_node **stack, int n);

// sorting
void		sort_stacks(t_node **st_a, t_node **st_b);
static void	move_min_on_top(t_node **st_a);
void		sort_three(t_node **stack);

// sorting utils
void		update_index(t_node *stack);
void		set_cheapest(t_node *stack);
void		prep_for_push(t_node **stack, t_node *new_top,
						void (*f_rr)(t_node **, bool),
						void (*f_rrr)(t_node **, bool));
bool		check_sintax(char *arg);

// common stack utils
int 		stack_len(t_node **stack);
bool 		is_stack_sorted(t_node **stack);
t_node		*get_cheapest(t_node *stack);
t_node		*get_min_node(t_node **stack);
t_node		*get_max_node(t_node **stack);

// stack A utils
void		init_stack_a(t_node **st_a, char **argv);
void		prepare_nodes_a(t_node *st_a, t_node *st_b);
void		set_target_a(t_node *st_a, t_node *st_b);
void		set_cost_a(t_node *st_a, t_node *st_b);
void		move_a_to_b(t_node **st_a, t_node **st_b);

// stack B utils
void		prepare_nodes_b(t_node *st_a, t_node *st_b);
void		set_target_b(t_node *st_a, t_node *st_b);
static void	move_b_to_a(t_node **st_a, t_node **st_b);

// swap
void		swap(t_node **stack);
void		sa(t_node **stack);
void		sb(t_node **stack);
void		ss(t_node **st_a, t_node **st_b);

// push
void		push(t_node **st_a, t_node **st_b);
void		pa(t_node **st_a, t_node **st_b);
void		pb(t_node **st_a, t_node **st_b);

// rotate
void		rotate(t_node **stack);
void		ra(t_node **stack);
void		rb(t_node **stack);
void		rr(t_node **stack);
void		keep_rotating(t_node **st_a, t_node **st_b, t_node *cheapest);

// reverse rotate
void		reverse_rotate(t_node **stack);
void		rra(t_node **st_a);
void		rrb(t_node **st_b);
void		rrr(t_node **st_a, t_node **st_b);
void		reverse_keep_rotating(t_node **st_a, t_node **st_b, t_node *cheapest);

#endif