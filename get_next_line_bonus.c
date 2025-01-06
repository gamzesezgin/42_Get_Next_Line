/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsezgin <gsezgin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:58:19 by gsezgin           #+#    #+#             */
/*   Updated: 2024/12/29 16:21:10 by gsezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_newline(int fd, char *text)
{
	char	*read_buffer;
	int		i;

	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(text, '\n') && i > 0)
	{
		i = read(fd, read_buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(read_buffer);
			free(text);
			return (NULL);
		}
		read_buffer[i] = '\0';
		text = ft_strjoin(text, read_buffer);
	}
	free(read_buffer);
	return (text);
}

char	*readline_from_buffer(char *text)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
	{
		new_line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*remove_before_line(char *text)
{
	int		i;
	int		j;
	char	*leftover_data;

	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	if (text == NULL || text[i] == '\0')
	{
		free(text);
		return (NULL);
	}
	leftover_data = (char *)malloc(sizeof(char) * (ft_strlen(text) - i));
	if (!leftover_data)
	{
		free(text);
		return (NULL);
	}
	i++;
	j = 0;
	while (text[i])
		leftover_data[j++] = text[i++];
	leftover_data[j] = '\0';
	free(text);
	return (leftover_data);
}

char	*get_next_line(int fd)
{
	static char	*text[10000];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text[fd] = read_until_newline(fd, text[fd]);
	if (!text[fd])
	{
		free(text[fd]);
		return (NULL);
	}
	new_line = readline_from_buffer(text[fd]);
	text[fd] = remove_before_line(text[fd]);
	return (new_line);
}
