/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:53 by icoman            #+#    #+#             */
/*   Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(int argc, char **argv)
{
	t_node	*st_a;
	t_node	*st_b;
	char	**split;

	st_a = NULL;
	st_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split || !split[0])
		{
			free(split);
			return (0);
		}
		init_stack_a(&st_a, split);
		free_split(split);
	}
	else
		init_stack_a(&st_a, argv + 1);
	if (!is_stack_sorted(st_a))
		sort_stacks(&st_a, &st_b);
	del_stack(&st_a);
	return (0);
}
