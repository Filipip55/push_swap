/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:02:23 by icoman            #+#    #+#             */
/*   Updated: 2026/04/02 14:17:53 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* ogni nodo rappresenta un buffer per un fd */
typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*get_node_by_fd(t_list **lst, int fd);
t_list	*lst_new_node(int fd, char *content);
char	*read_and_save(int fd, char *stash);
char	*strjoin_and_free(char *stash, char *buf);
char	*extract_line(char *stash);
char	*update_buffer(char *stash);
void	remove_node(t_list **lst, int fd);
char	*search_newline(char *s);
int		ft_strlen(char *s);

#endif