/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:48:36 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 20:00:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(int argc, char **argv)
{
	char	*haystack;
	char	*needle;
	char	*found;
	char	*found2;

	if (argc > 2)
	{
		haystack = argv[1];
		needle = argv[2];
		found = strstr(haystack, needle);
		found2 = ft_strstr(haystack, needle);
		if (found != 0)
		{
			printf("FOUND (lib)  : \"%s\"\n", found);
			printf("FOUND (mine) : \"%s\"\n", found2);
			printf("ADDR (lib)   : %p\n", found);
			printf("ADDR (mine)  : %p\n", found2);
		}
		else
		{
			printf("NOT FOUND (lib) : %p\n", found);
			printf("NOT FOUND (mine): %p\n", found2);
		}
	}
	return (0);
}
