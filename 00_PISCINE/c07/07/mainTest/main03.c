/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:51:37 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/21 00:15:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char 	*ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	char	*final_str;
	char	**strs;
	int		size;
	char	*sep;

	if (argc > 3)
	{
		size = atoi(argv[1]);
		sep = argv[2];
		strs = argv + 3;
		final_str = ft_strjoin(size, strs, sep);
		if (!final_str)
		{
			printf("ERROR - The function could not execute\n");
			return (0);
		}
		printf("Final STR: \"%s\"\n", final_str);
		free(final_str);
	}
	return (0);
}
