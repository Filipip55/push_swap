/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:12:52 by icoman            #+#    #+#             */
/*   Updated: 2026/04/03 21:31:40 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include "get_next_line.h"

bool	exec_push_swap(t_node **st_a, t_node **st_b, char *line);
bool	exec_rotate(t_node **st_a, t_node **st_b, char *line);
bool	execute_instruction(t_node **st_a, t_node **st_b, char *line);
void	read_instructions(t_node **st_a, t_node **st_b);

#endif