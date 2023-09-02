/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:48:36 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/15 09:12:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(int argc, char **argv)
{
	char	*str1;
	char	*str2;
	char	*dest1;
	char	*dest2;
	int		argv_index;
	int		size;
	int		returned1;
	int		returned2;

	argv_index = 1;
	while (argv_index < argc - 2)
	{
		str1 = argv[argv_index];
		str2 = argv[argv_index + 1];
		size = atoi(argv[argv_index + 2]);

		// Allocating memory for building result strings
		dest1 = (char *)malloc(size * sizeof(char));
		dest2 = (char *)malloc(size * sizeof(char));
		if (!dest1 || !dest2)
		{
			printf("MALLOC ERROR\n");
			return (0);
		}

		// Concatenation of str1 and str2 into dest and dest2, result comparison
		strcpy(dest1, str1);
		strcpy(dest2, str1);
		returned1 = strlcat(dest1, str2, size);
		returned2 = ft_strlcat(dest2, str2, size);
		printf("LIB            : \"%s\"\n", dest1);
		printf("MINE           : \"%s\"\n", dest2);
		printf("RETURNED (lib) : %d\n", returned1);
		printf("RETURNED (mine): %d\n", returned2);
		printf("\n");

		free(dest1);
		free(dest2);
		argv_index += 3;
	}
	return (0);
}
