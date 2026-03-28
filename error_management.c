/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:16:18 by icoman            #+#    #+#             */
/*   Updated: 2026/03/28 17:25:11 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Ritorna 1 se la stringa contiene solo numeri (con o senza segno) */
bool	check_sintax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (false);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (false);
	if (*str_n == '+' || *str_n == '-')
		str_n++;
	while (*str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (false);
		str_n++;
	}
	return (true);
}

/* Controlla se il valore n e' gia' presente nello stack */
bool	is_duplicate(t_node *node, int n)
{
	if (!node)
		return (false);
	while (node)
	{
		if (node->value == n)
			return (true);
		node = node->next;
	}
	return (false);
}

/* Libera tutta la memoria allocata per lo stack */
void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_node **stack)
{
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
