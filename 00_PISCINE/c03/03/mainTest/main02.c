/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:48:36 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 16:07:16 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(int argc, char **argv)
{
	char	*str1;
	char	*str2;
	char	*dest;
	char	*dest2;
	int		argv_index;

	argv_index = 1;
	while (argv_index < argc - 1)
	{
		str1 = argv[argv_index];
		str2 = argv[argv_index + 1];

		// Allocating memory for building result strings
		dest = (char *)malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
		dest2 = (char *)malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
		if (!dest || !dest2)
		{
			printf("MALLOC ERROR\n");
			return (0);
		}

		// Concatenation of str1 and str2 into dest and dest2, result comparison
		strcpy(dest, str1);
		strcpy(dest2, str1);
		dest = strcat(dest, str2);
		dest2 = ft_strcat(dest2, str2);
		printf("LIB : \"%s\"\n", dest);
		printf("MINE: \"%s\"\n", dest2);
		printf("\n");

		free(dest);
		free(dest2);
		argv_index += 2;
	}
	return (0);
}
