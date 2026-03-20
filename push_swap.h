/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:49:29 by icoman            #+#    #+#             */
/*   Updated: 2026/03/20 20:11:57 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include <stdarg.h>
# include "libft/libft.h"

# ifdef TO_PRINT
#  define TO_PRINT 1
# endif
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
void	add_node_front(node **stack, node *new_node);
int 	stack_len(node **stack);
bool 	is_stack_sorted(node **stack);
void	sort_three(node **stack);
node	*find_min(node **stack);
node	*find_max(node **stack);
void	del_node(node *old_node);
void	swap(node **stack);
void	sa(node **stack, bool to_print);
void	sb(node **stack, bool to_print);
void	ss(node **st_a, node **st_b, bool to_print);
void	pa(node **st_a, node **st_b, bool to_print);
void	pb(node **st_a, node **st_b, bool to_print);
void	rotate(node **stack);
void	ra(node **stack, bool to_print);
void	rb(node **stack, bool to_print);
void	rr(node **stack, bool to_print);
void	rotate_both(node **st_a, node **st_b, node *cheapest);

#endif