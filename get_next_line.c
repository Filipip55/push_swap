/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:02:19 by icoman            #+#    #+#             */
/*   Updated: 2026/02/13 00:05:35 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* legge linea per linea un file
	-una linea e' terminata da \n oppure EOF
	-trova o crea il nodo corrispondente a quel fd
	-legge dal file e accumula nel buffer corrispondente a quel fd
	-estrae dal buffer la riga da restituire
	-ripulisce il buffer in caso di una eventuale prossima chiamata
	-se il buffer è vuoto abbiamo raggiunto EOF,
		quindi elimina il nodo di quel fd */
char	*get_next_line(int fd)
{
	static t_list	*buffers_head = NULL;
	t_list			*curr;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	curr = get_node_by_fd(&buffers_head, fd);
	if (!curr)
		return (NULL);
	curr->content = read_and_save(fd, curr->content);
	if (!curr->content)
	{
		remove_node(&buffers_head, fd);
		return (NULL);
	}
	line = extract_line(curr->content);
	curr->content = update_buffer(curr->content);
	if (!curr->content)
		remove_node(&buffers_head, fd);
	return (line);
}

/* legge dal file descriptor e aggiorna 
	il buffer (che e' la stringa contenente i dati letti finora) */
char	*read_and_save(int fd, char *buffer)
{
	char	*tmp_buf;
	int		read_bytes;

	tmp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buf)
		return (NULL);
	read_bytes = 1;
	while (!search_newline(buffer) && read_bytes != 0)
	{
		read_bytes = read(fd, tmp_buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(tmp_buf);
			return (NULL);
		}
		tmp_buf[read_bytes] = '\0';
		buffer = strjoin_and_free(buffer, tmp_buf);
	}
	free(tmp_buf);
	return (buffer);
}

/* concatena buffer e tmp_buf per poi liberare buffer */
char	*strjoin_and_free(char *buffer, char *tmp_buf)
{
	char	*joined;
	int		i;
	int		j;

	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!tmp_buf)
		return (buffer);
	joined = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(tmp_buf) + 1));
	if (!joined)
		return (free(buffer), NULL);
	i = -1;
	while (buffer[++i])
		joined[i] = buffer[i];
	j = -1;
	while (tmp_buf[++j])
		joined[i + j] = tmp_buf[j];
	joined[i + j] = '\0';
	free(buffer);
	return (joined);
}

/* estrae la linea dal buffer */
char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + (buffer[i] == '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/* aggiorna il buffer liberando la parte già estratta */
char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_buffer)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}
