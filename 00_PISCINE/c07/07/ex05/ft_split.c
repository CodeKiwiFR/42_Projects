/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 00:07:59 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/22 08:27:17 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_strs(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_check_charset(str[i], charset))
		{
			i++;
			continue ;
		}
		count++;
		while (str[i] && !ft_check_charset(str[i], charset))
			i++;
	}
	return (count);
}

char	*ft_extract_str(char *str, int len)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_extract_strs(char **strs, char *str, char *charset)
{
	int	i;
	int	j;
	int	strs_index;

	i = 0;
	strs_index = 0;
	while (str[i] != '\0')
	{
		if (ft_check_charset(str[i], charset))
		{
			i++;
			continue ;
		}
		j = i;
		while (str[j] && !ft_check_charset(str[j], charset))
			j++;
		strs[strs_index] = ft_extract_str(str + i, j - i);
		if (strs[strs_index] == 0)
			return ;
		strs_index++;
		i = j;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		count_strs;
	char	**strs;
	int		charset_len;

	if (!str || !charset)
		return (0);
	count_strs = ft_count_strs(str, charset);
	strs = (char **)malloc((count_strs + 1) * sizeof(char *));
	if (!strs)
		return (0);
	charset_len = 0;
	while (charset[charset_len] != '\0')
		charset_len++;
	ft_extract_strs(strs, str, charset);
	strs[count_strs] = 0;
	return (strs);
}
