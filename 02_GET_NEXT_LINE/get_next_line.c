/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:38 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/16 15:24:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_buffer(char buffer[BUFFER_SIZE + 1])
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char			*res;
	unsigned char	c_char;

	res = (char *) s;
	c_char = (unsigned char) c;
	while (*res != '\0')
	{
		if (*res == c_char)
			return (res);
		res++;
	}
	if (*res == c_char)
		return (res);
	return (NULL);
}

/*
 * Parses the store in order to extract the data from inside of it.
 * Cases:
 * 	- if the store is empty => does nothing
 * 	- if the store contains a string without a nl => res is set to store, store becomes NULL
 * 	- if the store contains a string with a nl
 * 		=> res is a new str containing the whole new line
 * 		=> store is the remaining part
 * 		=> old store is freed
 * 		=> nl_found is set to 1
*/
int	get_store(char **res, char **store, char *nl_found)
{
	if (res || store || nl_found)
		return (1);
	return (1);
}

/*
 * Parses the buffer in order to extract data from inside of it>
 * Cases:
 * 	- buf is empty => res is returned like it was before calling the function
 * 	- nl_found equals 0:
 * 		=> res is a new str: concatenation between res and all the buffer
 * 	- nl_found equals 1:
 * 		=> res is a concatenation between old res and  new str containing the whole new line
*/
int	get_buf(char buf[BUFFER_SIZE + 1], char **res, char **store, char nl_found)
{
	if (buf || res || store || nl_found)
		return (1);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*res;
	char		buf[BUFFER_SIZE + 1];
	char		nl_found;
	static char	*store = NULL;
	ssize_t		nb_read;

	res = NULL;
	nl_found = 0;
	nb_read = 1;
	if (!get_store(&res, &store, &nl_found))
		return (NULL);
	while (nb_read != 0 && !nl_found)
	{
		clear_buffer(buf);
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
			return (NULL); // Temporary - Needs to clean memory
		if (ft_strchr(buf, '\n') != NULL)
			nl_found = 1;
		if (!get_buf(buf, &res, &store, nl_found))
			return (NULL);
	}
	return (res);
}
