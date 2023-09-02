/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:40:30 by pbigot            #+#    #+#             */
/*   Updated: 2023/08/29 17:42:28 by pbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_size(int fd)
{
	char	*tmp;
	int		size;
	int		count;

	size = 1;
	count = 0;
	tmp = (char *)malloc(100 * sizeof(char));
	if (!tmp)
		return (0);
	while (size > 0)
	{
		size = read(fd, tmp, 100);
		if (size == -1)
		{
			free(tmp);
			return (0);
		}
		count += size; 
	}
	free(tmp);
	return (count);
}

char	*get_data(char *name, int size)
{
	char	*str;
	int		fd;
	int		n;
	int		m;

	fd = open(name, O_RDONLY);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	n = read(fd, str, size);
	m = close(fd);
	if (n == -1 || m == -1)
	{
		free(str);
		return (0);
	}
	str[size] = 0;
	return (str);
}

char	*get_file_data(char *name)
{
	char	*str;
	int		fd;
	int		size;
	int		n;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	size = get_size(fd);
	n = close(fd);
	if (n == -1)
	{
		return (0);
	}
	if (size == 0)
		return (0);
	str = get_data(name, size);
	return (str);
}
