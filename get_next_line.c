/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkadlec <kkadlec@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:34:33 by kakadlec          #+#    #+#             */
/*   Updated: 2021/06/16 22:56:45 by kkadlec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	*buffer;
	//char	*temp;
	char	*ptr;
	ssize_t	read_status;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	if (!line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	ptr = NULL;
	*line = (char *)malloc(sizeof(char) * 1);
	while (ptr == NULL && read_status != 0)
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		ptr = ft_strchr(buffer, '\n');
		if (ptr)
		{
			*ptr = '\0';
			ptr++;
		}
		*line = ft_strjoin(*line, buffer);
	}
	return (0);
}
