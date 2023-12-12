/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_buffer_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:50:12 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/06 18:49:33 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fpf_buffer.h"

void	buffer_add_char(t_fpf_buffer *buffer, char c)
{
	if (buffer == NULL)
		return ;
	if (buffer->get_available_size(buffer) <= 1)
		buffer->flush(buffer);
	(buffer->content)[buffer->next_index] = c;
	buffer->next_index += 1;
	buffer->total_len += 1;
}

void	buffer_add_char_secure(t_fpf_buffer *buffer, char c, int fd)
{
	if (buffer == NULL)
		return ;
	if (buffer->get_available_size(buffer) <= 1)
	{
		buffer->put_fd(buffer, fd);
		buffer->flush(buffer);
	}
	buffer->add_char(buffer, c);
}

void	buffer_add_str(t_fpf_buffer *buffer, char *str)
{
	size_t	i;
	size_t	str_len;

	if (buffer == NULL || str == NULL)
		return ;
	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len)
	{
		buffer->add_char(buffer, str[i]);
		i++;
	}
}

void	buffer_add_str_secure(t_fpf_buffer *buffer, char *str, int fd)
{
	size_t	i;
	size_t	str_len;

	if (buffer == NULL || str == NULL)
		return ;
	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len)
	{
		buffer->add_char_secure(buffer, str[i], fd);
		i++;
	}
}
