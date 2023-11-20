/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:05:07 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/20 09:32:29 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		count;
	char	*read_line;

	if (argc == 0)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR - Could not open given file\n");
		return (-1);
	}
	count = 0;
	read_line = get_next_line(fd);
	while (read_line != NULL)
	{
		printf("LINE %3d: %s", count, read_line);
		count++;
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
