/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:04:47 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/20 15:35:12 by mhotting         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_len;

	s_len = ft_strlen(s);
	dup = (char *) malloc((s_len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, s_len + 1);
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*s_end;
	char	*s_start;
	size_t	tmp_len;

	if (s == NULL)
		return (NULL);
	s_start = (char *) s;
	tmp_len = ft_strlen(s_start);
	if (start > tmp_len)
		return (ft_strdup(""));
	s_start += start;
	s_end = s_start;
	while (*s_end != '\0' && ((unsigned int)(s_end - s_start) < len))
		s_end++;
	tmp_len = s_end - s_start;
	res = (char *) malloc((tmp_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s_start, tmp_len + 1);
	return (res);
}

/*
 *	Appends s2 at the end of s1.
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


