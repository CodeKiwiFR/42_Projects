/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:25:17 by gurousta          #+#    #+#             */
/*   Updated: 2023/08/26 15:10:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_is_charset(char c, char *charset)
{
	unsigned int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	unsigned int	i;
	int				word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] && !ft_is_charset(str[i], charset))
		{
			++word;
			while (str[i] && !ft_is_charset(str[i], charset))
				++i;
		}
		else
			++i;
	}
	return (word);
}

char	*ft_strdup_split(char *src, char *charset)
{
	unsigned int	i;
	char			*result;

	i = 0;
	while (src[i] && !ft_is_charset(src[i], charset))
		++i;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (src[i] && !ft_is_charset(src[i], charset))
	{
		result[i] = src[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_split2(char *str, char *charset, char **result)
{
	unsigned int	i; 
	unsigned int	index_result;

	i = 0;
	index_result = 0;
	while (str[i])
	{
		if (str[i] && !ft_is_charset(str[i], charset))
		{
			result[index_result++] = ft_strdup_split(str + i, charset);
			if (!result)
			{
				ft_free_tab(result);
				return (NULL);
			}
			while (str[i] && !ft_is_charset(str[i], charset))
				++i;
		}
		else
			++i;
	}
	result[index_result] = NULL;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char			**result;
	int				nb_words;

	nb_words = ft_count_word(str, charset);
	result = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	result = ft_split2(str, charset, result);
	if (!result)
		return (NULL);
	return (result);
}
