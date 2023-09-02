/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:32:06 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/21 19:15:17 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cpt;

	cpt = 0;
	while (*str)
	{
		str++;
		cpt++;
	}
	return (cpt);
}

char	*ft_create_empty_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (0);
	str[0] = '\0';
	return (str);
}

int	ft_eval_total_len(int size, char **strs, char *sep)
{
	int	cpt;
	int	i;
	int	j;

	cpt = 0;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			cpt++;
			j++;
		}
	}
	cpt += (size - 1) * ft_strlen(sep);
	return (cpt);
}

void	ft_make_join(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	j;
	int	dest_index;

	i = -1;
	dest_index = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
		{
			dest[dest_index] = strs[i][j];
			dest_index++;
		}
		if (i < size - 1)
		{
			j = -1;
			while (sep[++j] != '\0')
			{
				dest[dest_index] = sep[j];
				dest_index++;
			}
		}
	}
	dest[dest_index] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		str_total_len;
	char	*dest;

	if (size < 0)
		return (0);
	else if (size == 0)
		return (ft_create_empty_str());
	str_total_len = ft_eval_total_len(size, strs, sep);
	dest = (char *)malloc((str_total_len + 1) * sizeof(char));
	if (!dest)
		return (0);
	ft_make_join(size, strs, sep, dest);
	return (dest);
}
