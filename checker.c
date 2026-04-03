/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:12:28 by icoman            #+#    #+#             */
/*   Updated: 2026/04/03 21:30:52 by icoman           ###   ########.fr       */
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
	init_stack_a(&st_a, argv);
	read_instructions(&st_a, &st_b);
	if (is_stack_sorted(st_a) && st_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&st_a);
	free_stack(&st_b);
	return (0);
}

bool	exec_push_swap(t_node **st_a, t_node **st_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(st_a, false);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(st_b, false);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(st_a, st_b, false);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(st_a, st_b, false);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(st_a, st_b, false);
	else
		return (false);
	return (true);
}

bool	exec_rotate(t_node **st_a, t_node **st_b, char *line)
{
	if (!ft_strncmp(line, "ra\n", 3))
		ra(st_a, false);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(st_b, false);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(st_a, st_b, false);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(st_a, false);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(st_b, false);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(st_a, st_b, false);
	else
		return (false);
	return (true);
}

bool	execute_instruction(t_node **st_a, t_node **st_b, char *line)
{
	if (exec_push_swap(st_a, st_b, line))
		return (true);
	if (exec_rotate(st_a, st_b, line))
		return (true);
	return (false);
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
