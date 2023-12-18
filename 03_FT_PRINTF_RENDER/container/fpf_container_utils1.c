/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_container_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:50:12 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/18 17:09:40 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fpf_container.h"

/*
 *	Creates an instance of a container and initializes it components
 *	If an invalid FPF_CONTAINER_SIZE is given the error flag is set to true
 */
t_fpf_container	container_init(void)
{
	t_fpf_container	container;

	container.max_size = FPF_CONTAINER_SIZE;
	container.total_len = 0;
	container.error = false;
	container.flush = container_flush;
	container.get_available_size = container_get_available_size;
	container.set_error = container_set_error;
	container.add_char = container_add_char;
	container.add_char_secure = container_add_char_secure;
	container.add_chars_secure = container_add_chars_secure;
	container.add_str = container_add_str;
	container.add_str_secure = container_add_str_secure;
	container.put_fd = container_put_fd;
	container.flush(&container);
	if (FPF_CONTAINER_SIZE <= 2 || FPF_CONTAINER_SIZE > SIZE_MAX)
		container.error = true;
	return (container);
}

/*
 *	Flushes the given container by setting all its chars to '\0' and setting
 *	next_index to 0
 */
void	container_flush(t_fpf_container *container)
{
	size_t	i;

	if (container == NULL)
		return ;
	i = 0;
	while (i < container->max_size)
	{
		(container->content)[i] = '\0';
		i++;
	}
	container->next_index = 0;
}

/*
 *	Returns the container remaining size
 */
size_t	container_get_available_size(t_fpf_container *container)
{
	if (container == NULL)
		return (0);
	return (container->max_size - container->next_index);
}

/*
 *	Puts the container content to the given file descriptor
 *	In case of error, the container's error flag is set to true
 */
void	container_put_fd(t_fpf_container *container, int fd)
{
	ssize_t	returned;

	if (container == NULL)
		return ;
	returned = write(fd, container->content, container->next_index + 1);
	if (returned == -1)
		container->error = true;
}

/*
 *	Sets the container's error flag to true
 */
void	container_set_error(t_fpf_container *container)
{
	if (container == NULL)
		return ;
	container->error = true;
}
