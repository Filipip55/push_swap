/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:58:38 by icoman            #+#    #+#             */
/*   Updated: 2026/03/27 22:32:59 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	node	*st_a;
	node	*st_b;

	st_a = NULL;
	st_b = NULL;
	if (argc < 2)
		return (1);
	init_stack_a(&st_a, argv);
	if (!is_stack_sorted(st_a))
	{
		if (stack_len(st_a) == 2)
			sa(&st_a);
		else if (stack_len(st_a) == 3)
			sort_three(&st_a);
		else
			sort_stacks(&st_a, &st_b);
	}
	free(st_a);
	free(st_b);
	return (0);
}
