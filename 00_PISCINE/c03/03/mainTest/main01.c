/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:48:36 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 13:00:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(int argc, char **argv)
{
	unsigned int	size;

	if (argc > 2)
	{
		size = atoi(argv[3]);
		printf("Original : %d\n", strncmp(argv[1], argv[2], size));
		printf("Custom   : %d\n", ft_strncmp(argv[1], argv[2], size));
	}
	return (0);
}
