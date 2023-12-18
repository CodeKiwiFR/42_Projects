/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_container_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:10:17 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/18 17:10:19 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fpf_container.h"

/*
 *	Appends c to the container
 *	If the container is full, flushes it before adding
 *	next_index and total_len are updated
 */
void	container_add_char(t_fpf_container *container, char c)
{
	if (container == NULL)
		return ;
	if (container->get_available_size(container) <= 1)
		container->flush(container);
	(container->content)[container->next_index] = c;
	container->next_index += 1;
	container->total_len += 1;
}

/*
 *	Appends c to the container
 *	If the container is full:
 *		-	writes the container content to given file descriptor
 *		- 	flushes the container
 *		-	appends the given char
 */
void	container_add_char_secure(t_fpf_container *container, char c, int fd)
{
	if (container == NULL)
		return ;
	if (container->get_available_size(container) <= 1)
	{
		container->put_fd(container, fd);
		container->flush(container);
	}
	container->add_char(container, c);
}

/*
 *	Adds nb_chars chars to the container
 *	Appends each char one by one
 *	As soon as the container is full:
 *		-	writes the container content to given file descriptor
 *		- 	flushes the container
 *		-	appends the remaining chars
 *	WARNING: the string's len is not checked, an invalid nb_chars leads to
 *	undefined behaviours
 */
void	container_add_chars_secure(
	t_fpf_container *container,
	char *str,
	size_t nb_chars,
	int fd
)
{
	size_t	i;

	if (container == NULL)
		return ;
	i = 0;
	while (i < nb_chars)
	{
		container->add_char_secure(container, str[i], fd);
		i++;
	}
}

/*
 *	Appends str to the container
 *	Each char is added one by one and, as soon as the container is full,
 *	it is flushed
 */
void	container_add_str(t_fpf_container *container, char *str)
{
	size_t	i;
	size_t	str_len;

	if (container == NULL || str == NULL)
		return ;
	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len)
	{
		container->add_char(container, str[i]);
		i++;
	}
}

/*
 *	Appends str to the container
 *	Appends each char one by one
 *	As soon as the container is full:
 *		-	writes the container content to given file descriptor
 *		- 	flushes the container
 *		-	appends the remaining chars
 */
void	container_add_str_secure(t_fpf_container *container, char *str, int fd)
{
	size_t	i;
	size_t	str_len;

	if (container == NULL || str == NULL)
		return ;
	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len)
	{
		container->add_char_secure(container, str[i], fd);
		i++;
	}
}
