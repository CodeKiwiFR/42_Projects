/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:38 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/17 11:30:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Parses the store in order to extract the data from inside of it.
 * Cases:
 * 	-	if the store is empty => does nothing
 * 	-	if the store contains a string without a nl => res is set to store,
 * 		store becomes NULL
 * 	-	if the store contains a string with a nl
 * 		=> res is a new str containing the whole new line
 * 		=> store is the remaining part
 * 		=> old store is freed
 * 		=> nl_found is set to 1
*/
int	get_store(char **res, char **store, int *nl_found)
{
	char	**gnl_split_res;

	if (*store == NULL)
		return (1);
	gnl_split_res = gnl_split(*store, nl_found);
	free(*store);
	*store = NULL;
	if (gnl_split_res == NULL)
		return (0); // Temporary - Needs to clean memory
	if (gnl_split_res[0] != NULL)
		*res = gnl_split_res[0];
	if (gnl_split_res[1] != NULL)
		*store = gnl_split_res[1];
	free(gnl_split_res);
	return (1);
}

/*
 * Parses the buffer in order to extract data from inside of it>
 * Cases:
 * 	- buf is empty => res is returned like it was before calling the function
 * 	- nl_found equals 0:
 * 		=> res is a new str: concatenation between res and all the buffer
 * 	- nl_found equals 1:
 * 		=> res is a concatenation between old res and
 * 		new str containing the whole new line
*/
int	get_buf(char buf[BUFFER_SIZE + 1], char **res, char **store, int *nl_found)
{
	char	**gnl_split_res;

	gnl_split_res = gnl_split(buf, nl_found);
	if (gnl_split_res == NULL)
		return (0); // Temporary - Needs to clean memory
	if (gnl_split_res[0] != NULL)
	{
		if (!gnl_join(res, gnl_split_res[0]))
		{
			free(*res);
			free(gnl_split_res[0]);
			if (gnl_split_res[1] != NULL)
				free(gnl_split_res[1]);
			free(gnl_split_res);
			return (0);
		}
		free(gnl_split_res[0]);
	}
	if (gnl_split_res[1] != NULL)
		*store = gnl_split_res[1];
	free(gnl_split_res);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*res;
	char		buf[BUFFER_SIZE + 1];
	int			nl_found;
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
		if (!get_buf(buf, &res, &store, &nl_found))
			return (NULL);
	}
	return (res);
}
