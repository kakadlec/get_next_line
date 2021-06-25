/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkadlec <kkadlec@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:34:33 by kakadlec          #+#    #+#             */
/*   Updated: 2021/06/24 21:05:07 by kkadlec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static int	check_buffer(char *buffer)
{
	int	i;
	int	j;
	int	read_status;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && buffer[i] != '\n')
		i++;
	if (i == BUFFER_SIZE)
		read_status = 0;
	else
		read_status = (BUFFER_SIZE - 1) - i;
	while (j < BUFFER_SIZE)
	{
		if (i < BUFFER_SIZE)
			buffer[j] = buffer[++i];
		else
			buffer[j] = 0;
		j++;
	}
	return (read_status);
}

static int	read_fd(int fd, char *buffer, char **content)
{
	char	*ptr;
	int		read_status;
	int		i;

	read_status = check_buffer(buffer);
	if (read_status == 0)
		read_status = read(fd, buffer, BUFFER_SIZE);
	if (read_status == -1)
		return (-1);
	i = 0;
	while (i < read_status && buffer[i] != '\n')
		i++;
	ptr = ft_strjoin(*content, buffer, i);
	if (!ptr)
		return (-1);
	if (*content)
		free(*content);
	*content = ptr;
	if (buffer[i] == '\n')
		return (1);
	if (!read_status)
		return (-2);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*content;
	int			complete;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd > MAX_FILE_DESCRIPTOR)
		return (-1);
	content = NULL;
	complete = 0;
	content = ft_strnew(0);
	while (!complete)
	{
		complete = read_fd(fd, buffer, &content);
		*line = content;
		if (complete == -2)
			return (0);
		if (complete == -1)
			return (-1);
	}
	return (1);
}
