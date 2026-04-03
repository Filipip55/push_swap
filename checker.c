/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:12:28 by icoman            #+#    #+#             */
/*   Updated: 2026/04/03 18:00:40 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_node	*st_a;
	t_node	*st_b;

	st_a = NULL;
	st_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	init_stack_a(st_a, argv);
	read_instructions(&st_a, &st_b);
	if (is_sorted(st_a) && st_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&st_a);
	free_stack(&st_b);
	return (0);
}


void	read_instructions(t_node **st_a, t_node **st_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_instruction(st_a, st_b, line))
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			free_stack(st_a);
			free_stack(st_b);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

static int	exec_push_swap(t_node **a, t_node **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, false);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, false);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, false);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, false);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b, false);
	else
		return (0);
	return (1);
}

static int	exec_rotate(t_node **a, t_node **b, char *line)
{
	if (!ft_strncmp(line, "ra\n", 3))
		ra(a, false);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, false);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, false);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, false);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, false);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, false);
	else
		return (0);
	return (1);
}

bool	execute_instruction(t_node **a, t_node **b, char *line)
{
	if (exec_push_swap(a, b, line))
		return (true);
	if (exec_rotate(a, b, line))
		return (true);
	return (0);
}
