/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:28 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 19:27:32 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_res_array(char **res)
{
	size_t	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
}

static size_t	count_words(const char *s, char c)
{
	char	in_word;
	size_t	count;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (!in_word && *s != c)
		{
			in_word = 1;
			count++;
		}
		else if (in_word && *s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**extract_words(const char *s, char c, char **res, size_t nb_words)
{
	size_t	i;
	size_t	j;
	size_t	index_res;

	index_res = 0;
	i = 0;
	while (index_res < nb_words)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		j = i;
		while (s[j] != '\0' && s[j] != c)
			j++;
		res[index_res] = ft_substr(s, i, (j - i));
		if (res[index_res] == NULL)
		{
			free_res_array(res);
			free(res);
			return (NULL);
		}
		i = j + 1;
		index_res++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	char	**res;

	if (s == NULL)
		return (NULL);
	nb_words = count_words(s, c);
	res = (char **) ft_calloc(nb_words + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	return (extract_words(s, c, res, nb_words));
}
