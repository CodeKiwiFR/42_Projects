/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:45:45 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 15:37:17 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

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
	return (res);
}

int	ft_read_and_print_file(int fd)
{
	char	buffer[1000];
	int		nb_read_chars;
	int		i;

	nb_read_chars = 1;
	while (nb_read_chars > 0)
	{
		i = 0;
		nb_read_chars = 1;
		while (i < 1000)
			buffer[i++] = '\0';
		nb_read_chars = read(fd, buffer, 999);
		if (nb_read_chars == -1)
			return (-1);
		ft_putstr(buffer, 1);
		buffer[nb_read_chars] = '\0';
		if (nb_read_chars < 999)
			break ;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	res;
	int	fd;

	if (argc < 2)
	{
		res = ft_putstr("File name missing.\n", 2);
		return (0);
	}
	if (argc > 2)
	{
		res = ft_putstr("Too many arguments.\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		res = ft_putstr("Cannot read file.\n", 2);
		return (0);
	}
	res = ft_read_and_print_file(fd);
	if (res == -1)
		res = ft_putstr("Cannot read file.\n", 2);
	close(fd);
	return (0);
}
