/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkadlec <kkadlec@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:34:33 by kakadlec          #+#    #+#             */
/*   Updated: 2021/06/13 19:27:15 by kkadlec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
*   Até aqui estou lendo 100 bytes do arquivo
*   Proximos passos: usar o BUFFER_SIZE
*   Ler byte a byte até encontrar uma quebra de linha.
**/

int get_next_line(int fd, char **line)
{
    int result;

    *line = (char *)malloc(sizeof(char) * 100);
    if (!line)
        return (-1);
    result = read(fd, *line, 100);
    return (result);
}
