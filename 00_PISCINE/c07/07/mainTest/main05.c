/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:51:37 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/22 08:27:37 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split(char *str, char *charset);

int	main(int argc, char **argv)
{
	char	**result;
	char	*origin;
	char	*sep;
	int		i;

	if (argc == 3)
	{
		origin = argv[1];
		sep = argv[2];
		result = ft_split(origin, sep);
		if (!result)
		{
			printf("The function returned a NULL pointer\n");
			return (0);
		}
		i = 0;
		while (result[i] != 0)
		{
			printf("STR %2d: \"%s\"\n", i, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}
	return (0);
}
