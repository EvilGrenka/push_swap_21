/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:54:40 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/24 13:22:41 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(char **line)
{
	int	readed;
	int	i;

	i = 0;
	*line = malloc(4 * 1024 * 1024);
	if (!line)
		return (-1);
	readed = read(0, *line + i, 1);
	while (readed > 0)
	{
		if ((*line)[i] == '\n')
			break ;
		i++;
		readed = read(0, *line + i, 1);
	}
	(*line)[i] = '\0';
	return (readed);
}
