/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:49:29 by icoman            #+#    #+#             */
/*   Updated: 2026/03/27 23:30:30 by icoman           ###   ########.fr       */
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
	push_cost -> il costo per spostare il nodo
	is_cheapest -> true se ha il costo piu basso
	above_half -> true se il nodo si trova nella 
				prima meta dello stack 
	target -> nodo a cui puntare nello spostamento
	next e prev -> puntano al nodo successivo e precedente */
typedef struct	s_list
{
	int				value;
	int				index;
	int				push_cost;
	bool			is_cheapest;
	bool			above_median;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
} 		node;

static void	add_node_back(node **stack, int n);

// sorting
void		sort_stacks(node **st_a, node **st_b);
static void	move_min_on_top(node **st_a);
void		sort_three(node **stack);

// sorting utils
void		update_index(node *stack);
void		set_cheapest(node *stack);
void		prep_for_push(node **stack, node *new_top,
						void (*f_rr)(node **, bool),
						void (*f_rrr)(node **, bool));
bool		check_sintax(char *arg);

// common stack utils
int 		stack_len(node **stack);
bool 		is_stack_sorted(node **stack);
node		*get_cheapest(node *stack);
node		*get_min_node(node **stack);
node		*get_max_node(node **stack);

// stack A utils
void		init_stack_a(node **st_a, char **argv);
void		prepare_nodes_a(node *st_a, node *st_b);
void		set_target_a(node *st_a, node *st_b);
void		set_cost_a(node *st_a, node *st_b);
void		move_a_to_b(node **st_a, node **st_b);

// stack B utils
void		prepare_nodes_b(node *st_a, node *st_b);
void		set_target_b(node *st_a, node *st_b);
static void	move_b_to_a(node **st_a, node **st_b);

// swap
void		swap(node **stack);
void		sa(node **stack);
void		sb(node **stack);
void		ss(node **st_a, node **st_b);

// push
void		push(node **st_a, node **st_b);
void		pa(node **st_a, node **st_b);
void		pb(node **st_a, node **st_b);

// rotate
void		rotate(node **stack);
void		ra(node **stack);
void		rb(node **stack);
void		rr(node **stack);
void		keep_rotating(node **st_a, node **st_b, node *cheapest);

// reverse rotate
void		reverse_rotate(node **stack);
void		rra(node **st_a);
void		rrb(node **st_b);
void		rrr(node **st_a, node **st_b);
void		reverse_keep_rotating(node **st_a, node **st_b, node *cheapest);

#endif