/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:10:06 by gurousta          #+#    #+#             */
/*   Updated: 2023/08/26 21:48:47 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;
	int		str_len;

	str_len = ft_strlen(str);
	dest = (char *)malloc((str_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_isspace(char c)
{
	if (
		c == ' ' || c == '\n' || c == '\f'
		|| c == '\v' || c == '\r' || c == '\t'
	)
		return (1);
	return (0);
}

char	*ft_strtrim(char *str)
{
	int		start;
	int		end;
	int		final_len;
	int		i;
	char	*res;

	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && ft_isspace(str[start]))
		start++;
	while (end >= 0 && str[end] && ft_isspace(str[end]))
		end--;
	if ((start == 0 && end == 0 && ft_strlen(str) == 0) || end < start)
		final_len = 0;
	else
		final_len = end - start + 1;
	res = (char *)malloc((final_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < final_len)
		res[i++] = str[start++];
	res[final_len] = '\0';
	return (res);
}

int	ft_str_array_len(char **array)
{
	int	count;

	count = 0;
	while (array[count] != NULL)
		count++;
	return (count);
}
