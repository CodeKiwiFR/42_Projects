/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:44:47 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/28 20:02:29 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
 * STILL TO CHECK:
 * 	- all buffer functions;
 * 	- think about weird BUFFER_SIZE;
 */

void	buffer_init(t_buffer *buffer)
{
	if (buffer == NULL)
		return ;
	buffer_flush(buffer);
	buffer->next_index = 0;
	buffer->total_len = 0;
	buffer->add_char = buffer_add_char;
	buffer->add_string = buffer_add_string;
	buffer->flush = buffer_flush;
	buffer->put_fd = buffer_put_fd;
	buffer->is_full = buffer_is_full;
	buffer->is_addable = buffer_is_addable;
}

void	buffer_add_char(t_buffer *buffer, char c)
{
	if (buffer == NULL)
		return ;
	if (buffer->is_full(buffer))
		buffer->flush(buffer);
	(buffer->content)[buffer->next_index] = c;
	buffer->next_index += 1;
	buffer->total_len += 1;
}

void	buffer_add_string(t_buffer *buffer, char *str)
{
	size_t	len;
	size_t	i;

	if (buffer == NULL || str == NULL)
		return ;
	len = ft_strlen(str);
	if (len > BUFFER_SIZE)
		return ;
	if (!(buffer->is_addable(buffer, len)))
		buffer->flush(buffer);
	i = 0;
	while (i < len)
	{
		buffer->add_char(buffer, str[i]);
		i++;
	}
	return ;
}

void	buffer_flush(t_buffer *buffer)
{
	size_t	i;

	if (buffer == NULL)
		return ;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		(buffer->content)[i] = '\0';
		i++;
	}
	buffer->next_index = 0;
}

ssize_t	buffer_put_fd(t_buffer *buffer, int fd)
{
	ssize_t	returned;

	if (buffer == NULL)
		return (-1);
	returned = write(fd, buffer->content, buffer->next_index - 1);
	if (returned == -1)
		return (-1);
	buffer->flush(buffer);
	return (returned);
}

bool	buffer_is_full(t_buffer *buffer)
{
	if (buffer == NULL)
		return (false);
	if (buffer->next_index >= BUFFER_SIZE)
		return (true);
	return (false);
}

bool	buffer_is_addable(t_buffer *buffer, size_t len)
{
	if (buffer == NULL)
		return (false);
	if (buffer->next_index + len > BUFFER_SIZE)
		return (false);
	return (true);
}
