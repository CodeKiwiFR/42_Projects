/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:56:40 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 11:12:32 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	*str1 = "Bonjour";
	char	*str2 = "Hi";
	char	*str3 = "Piscine";
	char	*str4 = "";
	char	*dest;
	char	*dest2;

	dest = (char *)malloc(20 * sizeof(char));
	dest2 = (char *)malloc(20 * sizeof(char));
	if (dest && dest2)
	{
		dest = strcpy(dest, str1);
		dest2 = ft_strcpy(dest2, str1);
		printf("Original1: %s\n", dest);
		printf("Exercise1: %s\n", dest2);

		dest = strcpy(dest, str2);
		dest2 = ft_strcpy(dest2, str2);
		printf("Original2: %s\n", dest);
		printf("Exercise2: %s\n", dest2);

		dest = strcpy(dest, str3);
		dest2 = ft_strcpy(dest2, str3);
		printf("Original3: %s\n", dest);
		printf("Exercise3: %s\n", dest2);

		dest = strcpy(dest, str4);
		dest2 = ft_strcpy(dest2, str4);
		printf("Original4: %s\n", dest);
		printf("Exercise4: %s\n", dest2);
	}

	return (0);
}
