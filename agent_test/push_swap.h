/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				push_cost;
	bool			cheapest;
	bool			above_half;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* init_stack.c */
void	check_syntax(const char *str);
int		is_duplicate(t_node *stack, int n);
void	add_node_back(t_node **stack, int n);
void	free_errors(t_node **st_a);
void	init_stack_a(t_node **st_a, char **argv);

/* stack_utils.c */
int		stack_len(t_node *stack);
t_node	*find_last(t_node *stack);
int		is_stack_sorted(t_node *stack);
t_node	*find_min(t_node *stack);
t_node	*find_max(t_node *stack);
void	del_stack(t_node **stack);

/* swap.c */
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **st_a, t_node **st_b);

/* push.c */
void	pa(t_node **st_a, t_node **st_b);
void	pb(t_node **st_a, t_node **st_b);

/* rotate.c */
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **st_a, t_node **st_b);

/* rev_rotate.c */
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **st_a, t_node **st_b);

/* sort_three.c */
void	sort_three(t_node **stack);

/* sort_cost.c */
void	set_above_half(t_node *stack, int len);
void	find_target_b(t_node *node_a, t_node *st_b);
void	set_node_cost(t_node *node, t_node *st_b, int pos_a, int len_b);
void	prepare_nodes_a(t_node *st_a, t_node *st_b);
t_node	*find_cheapest(t_node *st_a);

/* sort_exec.c */
void	find_target_a(t_node *node_b, t_node *st_a);
void	rotate_both(t_node **st_a, t_node **st_b, t_node *cheapest);
void	move_a_to_b(t_node **st_a, t_node **st_b);
void	push_b_to_a(t_node **st_a, t_node **st_b);
void	sort_stacks(t_node **st_a, t_node **st_b);

#endif
