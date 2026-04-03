/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:58:38 by icoman            #+#    #+#             */
/*   Updated: 2026/04/03 21:42:49 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Punto di partenza, per mostare il numero di mosse eseguite 
	aggiungi queste linee alla fine di questo main
	
	ft_printf("Numero di mosse: ", true);
	ft_printf("\n", false); 
	*/
int	main(int argc, char **argv)
{
	t_node	*st_a;
	t_node	*st_b;

	st_a = NULL;
	st_b = NULL;
	if (argc < 2)
		return (1);
	init_stack_a(&st_a, argv);
	if (!is_stack_sorted(st_a))
	{
		if (stack_len(st_a) == 2)
			sa(&st_a, true);
		else if (stack_len(st_a) == 3)
			sort_three(&st_a);
		else
			sort_stacks(&st_a, &st_b);
	}
	free_stack(&st_a);
	free_stack(&st_b);
	return (0);
}
