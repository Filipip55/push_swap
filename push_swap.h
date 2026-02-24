/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:49:29 by icoman            #+#    #+#             */
/*   Updated: 2026/02/24 23:20:42 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_list
{
	int				n;
	struct s_list	*next;
	struct s_list	*prev;
} 		t_list;

 

#endif