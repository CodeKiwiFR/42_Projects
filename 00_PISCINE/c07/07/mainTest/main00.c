/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:09:20 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/17 21:29:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src);

int	main(int argc, char **argv)
{
	char	*src;
	char	*dest1;
	char	*dest2;

	if (argc > 1)
	{
		src = argv[1];
		dest1 = strdup(src);
		dest2 = ft_strdup(src);
		printf("STR (lib) : %s\n", dest1);
		printf("PTR (lib) : %p\n", dest1);
		printf("STR (mine): %s\n", dest2);
		printf("PTR (mine): %p\n", dest2);
		free(dest1);
		free(dest2);
	}
	return (0);
}
