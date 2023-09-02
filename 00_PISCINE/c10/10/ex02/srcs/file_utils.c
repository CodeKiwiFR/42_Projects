/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:42:09 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 15:16:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_read_and_print_file(int fd)
{
	char	buffer[10000];
	int		nb_read_chars;
	int		i;
	int		res;

	nb_read_chars = 1;
	while (nb_read_chars > 0)
	{
		i = 0;
		nb_read_chars = 1;
		while (i < 10000)
			buffer[i++] = '\0';
		nb_read_chars = read(fd, buffer, 9999);
		if (nb_read_chars == -1)
			return (-1);
		res = ft_putstr(buffer, 1);
		if (res == -1)
			return (-1);
		buffer[nb_read_chars] = '\0';
		if (nb_read_chars < 9999 && fd != 0)
			break ;
	}
	return (1);
}

int	ft_check_flags(int argc, char **argv)
{
	int	current_len;
	int	i;

	i = 0;
	while (i < argc)
	{
		current_len = ft_strlen(argv[i]);
		if (current_len > 1 && argv[i][0] == '-')
		{
			ft_putstr("cat: invalid option -- '", 2);
			ft_putchar(argv[i][1], 2);
			ft_putstr("'\nTry 'cat --help' for more information.\n", 2);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_open_error(char *file_name)
{
	int	res;

	res = 0;
	res += ft_putstr("cat: ", 2);
	if (ft_file_name_need_quotes(file_name))
	{
		res += ft_putchar('\'', 2);
		res += ft_putstr(file_name, 2);
		res += ft_putchar('\'', 2);
	}
	else
		res += ft_putstr(file_name, 2);
	res += ft_putstr(": ", 2);
	res += ft_putstr(strerror(errno), 2);
	res += ft_putchar('\n', 1);
	if (res != 5)
		return (-1);
	return (1);
}

int	ft_read_all_files(int argc, char **argv)
{
	int	i;
	int	fd;
	int	res;

	i = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 1 && argv[i][0] == '-')
			res = ft_read_and_print_file(0);
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			ft_open_error(argv[i]);
		else
		{
			res = ft_read_and_print_file(fd);
			if (res == -1)
			{
				ft_putstr(strerror(errno), 2);
				ft_putchar('\n', 2);
			}
			close(fd);
		}
		i++;
	}
	return (1);
}
