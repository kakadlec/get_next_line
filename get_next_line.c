/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkadlec <kkadlec@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:34:33 by kakadlec          #+#    #+#             */
/*   Updated: 2021/06/17 22:54:47 by kkadlec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s) + 1;
	if (!s)
		return (NULL);
	copy = (char *)malloc(len * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len);
	return (copy);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	get_next_line(int fd, char **line)
{
	char	*buffer;
	//char	*temp;
	char	*ptr;
	static char *rest;
	ssize_t	read_status;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	*line = ft_strnew(0);
	if (!buffer || !(*line)|| BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	if (rest)
		ft_strlcpy(*line, rest, ft_strlen(rest) + 1);
	ptr = NULL;
	while (!ptr && read_status != 0)
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		buffer[read_status] = '\0';
		ptr = ft_strchr(buffer, '\n');
		if (ptr)
		{
			*ptr = '\0';
			ptr++;
			rest = ft_strdup(ptr);
		}
		*line = ft_strjoin(*line, buffer);
	}
	free(buffer);
	if (!ptr && read_status == 0)
		return (0);
	else
		return (1);
}
