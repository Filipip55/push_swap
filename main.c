/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:58:38 by icoman            #+#    #+#             */
/*   Updated: 2026/02/27 17:59:02 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	node	*st_a;
	node	*st_b;

	st_a = NULL;
	st_b = NULL;
	if (argc < 2 || !argv[1][0])
		return (write(2, "Error\n", 6), 1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' '); //non e' lo stesso split, modificala e usa una variabile statica per tenere traccis di dove sei arrivato
	init_stack_a(&st_a);
	if (!is_stack_sorted(st_a))
	{
		if (stack_len(st_a) == 2)
			sa(&st_a, false);
		else if (stack_len(st_a) == 3)
			sort_three(&st_a);
		else
			sort_stacks(&st_a, &st_b);
	}
	free(st_a);
	free(st_b);
	return (0);
}
