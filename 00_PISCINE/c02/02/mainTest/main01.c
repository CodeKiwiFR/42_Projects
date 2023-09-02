/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:56:40 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 11:22:57 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(int argc, char **argv)
{
	char			*dest;
	char			*dest2;
	int				arg_index;
	unsigned int	size;

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
		dest = strncpy(dest, argv[arg_index], size);
		dest2 = ft_strncpy(dest2, argv[arg_index], size);
		printf("Original: %s\n", dest);
		printf("Exercise: %s\n\n", dest2);
		arg_index += 2;
	}

	return (0);
}
