/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:56:40 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 11:29:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(int argc, char **argv)
{
	char			*dest;
	char			*dest2;
	int				arg_index;
	unsigned int	size;
	unsigned int	returned;
	unsigned int	returned2;

	dest = (char *)malloc(100 * sizeof(char));
	dest2 = (char *)malloc(100 * sizeof(char));
	if (!dest || !dest2)
	{
		return (0);
	}

	arg_index = 1;
	while (arg_index + 1 < argc)
	{
		size = atoi(argv[arg_index + 1]);
		returned = strlcpy(dest, argv[arg_index], size);
		returned2 = ft_strlcpy(dest2, argv[arg_index], size);
		printf("Original: %s\n", dest);
		printf("Exercise: %s\n", dest2);
		printf("Returned  : %u\n", returned);
		printf("Returned2 : %u\n\n", returned2);
		arg_index += 2;
	}

	return (0);
}
