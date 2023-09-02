/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 08:40:56 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/23 11:22:57 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		str_len;
	char	*dest;

	str_len = ft_strlen(str);
	dest = (char *)malloc((str_len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < str_len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;

	if (!av)
		return (0);
	array = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!array)
		return (0);
	i = -1;
	while (++i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		if (!array[i].copy)
			break ;
	}
	if (i < ac)
	{
		free(array);
		return (0);
	}
	else
		array[i].str = 0;
	return (array);
}
