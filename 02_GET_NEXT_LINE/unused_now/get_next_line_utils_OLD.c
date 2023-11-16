/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_OLD.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:04:47 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/16 14:51:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	returned_val;

	i = 0;
	while (dst[i] != '\0')
		i++;
	if (i > size)
		returned_val = ft_strlen(src) + size;
	else
		returned_val = i + ft_strlen(src);
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (returned_val);
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

char	*ft_strappend(char **s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_res;

	if (*s1 == NULL)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(*s1);
	if (s2 == NULL)
		len_s2 = 0;
	else
		len_s2 = ft_strlen(s2);
	len_res = len_s1 + len_s2;
	res = (char *) malloc((len_res + 1) * sizeof(char));
	if (res == NULL)
	{
		free(*s1);
		return (NULL);
	}
	ft_strlcpy(res, *s1, len_s1 + 1);
	ft_strlcat(res, s2, len_res + 1);
	return (res);
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

int	split_lines(char **res, size_t nl_index, char *src, char **line_end)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	*res = (char *) malloc((nl_index + 1) * sizeof(char));
	if (*res == NULL)
		return (0);
	ft_strlcpy(*res, src, nl_index + 1);
	if (nl_index == len_src)
	{
		*line_end = NULL;
		return (1);
	}
	if (nl_index == len_src)
		return (1);
	*line_end = (char *) malloc((len_src - nl_index + 1) * sizeof(char));
	if (line_end == NULL)
	{
		free(*res);
		*res = NULL;
		return (0);
	}
	ft_strlcpy(*line_end, src + nl_index, len_src - nl_index + 1);
	return (1);
}

int	get_from_storage(char **res, char **fd_storage, char *new_line_found)
{
	size_t	i;
	char	*temp_str;

	if (*fd_storage == NULL)
		return (1);
	i = 0;
	temp_str = NULL;
	while ((*fd_storage)[i] != '\0' && (*fd_storage)[i] != '\n')
		i++;
	if ((*fd_storage)[i] == '\n')
	{
		*new_line_found = 1;
		i++;
	}
	if (!split_lines(res, i, *fd_storage, &temp_str))
		return (0); // Check if the memory has to be freed
	free(*fd_storage);
	*fd_storage = temp_str;
	return (1);
}

int	get_from_buffer(char buffer[BUFFER_SIZE + 1], char **res, char **fd_storage, char new_line_found)
{
	size_t	i;
	char	*temp_res;

	if (new_line_found)
	{
		i = 0;
		temp_res = NULL;
		while (buffer[i] != '\0' && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
			i++;
		if (!split_lines(&temp_res, i, buffer, fd_storage))
			return (0); // Check if the memory has to be freed
		ft_strappend(res, temp_res);
		free(temp_res);
		if (*res == NULL)
			return (0);
		return (1);
	}
	ft_strappend(res, buffer);
	if (*res == NULL)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*res;
	char		buffer[BUFFER_SIZE + 1];
	char		new_line_found;
	static char	*fd_storage = NULL;
	ssize_t		read_chars;

	res = NULL;
	new_line_found = 0;
	read_chars = 1;
	if (!get_from_storage(&res, &fd_storage, &new_line_found))
		return (NULL);
	while (read_chars != 0 && !new_line_found)
	{
		clear_buffer(buffer);
		read_chars = read(fd, buffer, BUFFER_SIZE);
		if (read_chars == -1)
			return (NULL); // Temporary - Needs to clean memory
		if (ft_strchr(buffer, '\n') != NULL)
			new_line_found = 1;
		if (!get_from_buffer(buffer, &res, &fd_storage, new_line_found))
			return (NULL);
	}
	return (res);
}
