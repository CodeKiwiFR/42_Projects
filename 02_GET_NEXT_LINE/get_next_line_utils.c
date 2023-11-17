/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:04:47 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/17 11:31:07 by mhotting         ###   ########.fr       */
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

char	**gnl_split(char buf[BUFFER_SIZE + 1], int *nl_found)
{
	char	**res;
	size_t	i;
	size_t	j;

	res = (char **) malloc(2 * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		*nl_found = 1;
		i++;
	}
	res[0] = gnl_substr(buf, 0, i);
	j = i;
	while (buf[j] != '\0')
		j++;
	res[1] = gnl_substr(buf, i, j - i);
	return (res);
}
