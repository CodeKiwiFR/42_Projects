/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:04:47 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/20 08:26:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_memory(char **res, char **store, char **split_result)
{
	if (res == NULL || store == NULL)
		return ;
	if (*res != NULL)
	{
		free(*res);
		*res = NULL;
	}
	if (*store != NULL)
	{
		free(*store);
		*store = NULL;
	}
	if (split_result != NULL)
	{
		if (split_result[0] != NULL)
			free(split_result[0]);
		if (split_result[1] != NULL)
			free(split_result[1]);
		free(split_result);
	}
}

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

char	*gnl_substr(char *src, size_t start, size_t len)
{
	char	*res;
	size_t	i;

	if (len == 0)
		return (NULL);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = src[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

/*
 *	Appends s2 at the en of s1.
 *	A new string is allocated and s1 is freed.
 *	In case of error, nothing happens and 0 is returned.
 *	If s1 or s2 is NULL, it is considered as empty.
 *	On success 1 is returned.
 */
int	gnl_join(char **s1, char *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = 0;
	len_s2 = 0;
	if (*s1 != NULL)
		while ((*s1)[len_s1] != '\0')
			len_s1++;
	if (s2 != NULL)
		while (s2[len_s2] != '\0')
			len_s2++;
	res = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	i = -1;
	while (++i < len_s1)
		res[i] = (*s1)[i];
	while (i < len_s1 + len_s2)
		res[i++] = *(s2++);
	res[i] = '\0';
	free(*s1);
	*s1 = res;
	return (1);
}

/*
 *	Splits str into two strings where the first '\n' is encountered
 *	Sets nl_found to 1 when a new line has been found
 *	Returns NULL in case of error
 *	Edge cases:
 *		-	if str is NULL, NULL is returned;
 *		-	if str is empty [NULL, NULL] is returned;
 *		-	if str does not contain '\n' or does not contain anything
 *			after '\n' [ptr, NULL] is returned;
 */
char	**gnl_split(char *str, int *nl_found)
{
	char	**res;
	size_t	i;
	size_t	j;

	if (str == NULL)
		return (NULL);
	res = (char **) malloc(2 * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*nl_found = 1;
		i++;
	}
	res[0] = gnl_substr(str, 0, i);
	j = i;
	while (str[j] != '\0')
		j++;
	res[1] = gnl_substr(str, i, j - i);
	return (res);
}
