/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:38 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/14 15:59:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	reset_buffer(char buffer[BUFFER_SIZE + 1])
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*append_buffer(char **res, char buffer[BUFFER_SIZE + 1])
{
	
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*res;
	static char	*buffer_rest = NULL;
	ssize_t		returned;
	char		line_break_encountered;
	
	res = NULL;
	returned = 1;
	line_break_encountered = 0;
	while (returned != 0 && !line_break_encountered)
	{
		reset_buffer(buffer);
		returned = read(fd, buffer, BUFFER_SIZE);
		if (returned == -1)
			// check in order to free vars and return NULL
		append_buffer(&res, buffer, &buffer_res);
		if (ft_strchr(buffer, '\n') == NULL)
		else
			line_break_encountered = 1;
	}
	if (line_break_encountered)
		extract_line_end();
}
