/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:02:12 by icoman            #+#    #+#             */
/*   Updated: 2026/02/13 00:03:28 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* crea un nuovo nodo della lista */
t_list	*lst_new_node(int fd, char *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->content = content;
	node->next = NULL;
	return (node);
}

/* ricerca nodo per fd, se non esiste 
	crea nuovo nodo e lo mette in testa */
t_list	*get_node_by_fd(t_list **lst, int fd)
{
	t_list	*curr;
	t_list	*new_node;

	curr = *lst;
	while (curr != NULL)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	new_node = lst_new_node(fd, NULL);
	if (!new_node)
		return (NULL);
	new_node->next = *lst;
	*lst = new_node;
	return (new_node);
}

/* rimuove il nodo corrispondente al fd */
void	remove_node(t_list **lst, int fd)
{
	t_list	*current;
	t_list	*prev;

	current = *lst;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev == NULL)
				*lst = current->next;
			else
				prev->next = current->next;
			if (current->content)
				free(current->content);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

/* ricerca e restituisce la prima 
	istanza di newline in s */
char	*search_newline(char *s)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/* mi devi davvero leggere? */
int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}
