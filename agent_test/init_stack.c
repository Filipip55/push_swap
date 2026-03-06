/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** check_syntax: validates that str represents a valid integer string.
** Accepts optional leading '+'/'-', then only digit characters.
** Writes "Error\n" to stderr and exits 1 on invalid input.
*/
void	check_syntax(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}

/*
** is_duplicate: returns 1 if value n already exists in stack, 0 otherwise.
*/
int	is_duplicate(t_node *stack, int n)
{
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/*
** add_node_back: allocates a new t_node with value n and appends it to *stack.
** Maintains doubly-linked list: sets next/prev pointers correctly.
*/
void	add_node_back(t_node **stack, int n)
{
	t_node	*new_node;
	t_node	*last;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = n;
	new_node->push_cost = 0;
	new_node->cheapest = false;
	new_node->above_half = false;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = find_last(*stack);
	last->next = new_node;
	new_node->prev = last;
}

/*
** free_errors: frees stack a, prints "Error\n" to stderr, exits 1.
*/
void	free_errors(t_node **st_a)
{
	del_stack(st_a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

/*
** init_stack_a: iterates argv[], validates each token, checks for int overflow,
** duplicates, then builds the doubly-linked stack a.
*/
void	init_stack_a(t_node **st_a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		check_syntax(argv[i]);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(st_a);
		if (is_duplicate(*st_a, (int)n))
			free_errors(st_a);
		add_node_back(st_a, (int)n);
		i++;
	}
}
