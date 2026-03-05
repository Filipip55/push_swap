/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:49:29 by icoman            #+#    #+#             */
/*   Updated: 2026/03/05 18:05:44 by icoman           ###   ########.fr       */
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
	cheapest -> true se ha il costo piu basso
	above_half -> true se il nodo si trova nella 
				prima meta dello stack 
	target -> nodo a cui puntare nello spostamento
	next e prev -> puntano al nodo successivo e precedente */
typedef struct	s_list
{
	int				value;
	int				index;
	int				push_cost;
	bool			cheapest;
	bool			above_half;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
} 		node;

void	add_node_front(node **stack, node *new_node);
int 	stack_len(node **stack);
bool 	is_stack_sorted(node **stack);
void	sort_three(node **stack);
node	*find_min(node **stack);
node	*find_max(node **stack);
void	del_node(node *old_node);
void	sa(node **stack);
void	sb(node **stack);
void	ss(node **st_a, node **st_b);

#endif