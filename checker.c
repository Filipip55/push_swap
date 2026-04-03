/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:12:28 by icoman            #+#    #+#             */
/*   Updated: 2026/04/03 17:22:38 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int argc, char const **argv)
{
	/* code */
	return 0;
}


void	read_instructions(t_node **st_a, t_node **st_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		/* 
		** Qui devi inserire la logica per confrontare la stringa 'line'
		** con le mosse valide (sa, pb, rra, ecc.) ed eseguire la mossa
		** corrispondente sugli stack. Se l'istruzione non esiste,
		** devi gestire l'errore stampando "Error\n" sullo stderr.
		*/
		
		free(line);
		line = get_next_line(0);
	}
}
