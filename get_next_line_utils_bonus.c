/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsezgin <gsezgin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:59:33 by gsezgin           #+#    #+#             */
/*   Updated: 2024/12/29 16:03:24 by gsezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

char	*ft_strjoin(char *text, char *read_buffer)
{
	int		i;
	int		j;
	char	*str;

	if (!read_buffer)
		return (NULL);
	if (!text)
	{
		text = (char *)malloc(sizeof(char));
		if (!text)
			return (NULL);
		text[0] = '\0';
	}
	str = (char *)malloc(ft_strlen(text) + ft_strlen(read_buffer) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (text[++i] != '\0')
		str[i] = text[i];
	j = -1;
	while (read_buffer[++j] != '\0')
		str[i + j] = read_buffer[j];
	str[i + j] = '\0';
	free(text);
	return (str);
}
