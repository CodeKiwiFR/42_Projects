/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:19:26 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 15:21:38 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(char *str, int fd)
{
	int	count;
	int	res;

	count = 0;
	while (*str)
	{
		res = ft_putchar(*str, fd);
		if (res == -1)
			return (-1);
		count += res;
		str++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	count;

	if (!str)
		return (-1);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_isspace(char c)
{
	if (
		c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v'
	)
		return (1);
	return (0);
}

int	ft_file_name_need_quotes(char *file_name)
{
	int	len;
	int	i;

	len = ft_strlen(file_name);
	if (len < 1)
		return (1);
	i = 0;
	while (i < len)
	{
		if (ft_isspace(file_name[i]))
			return (1);
		i++;
	}
	return (0);
}
