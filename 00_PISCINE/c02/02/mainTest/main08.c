/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main08.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:56:40 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 12:38:04 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strlowcase(char *str);

int	main(int argc, char **argv)
{
	char *str;

	str = (char *)malloc(100 * sizeof(char));
	if (str && argc > 1)
	{
		strcpy(str, argv[1]);
		str =  ft_strlowcase(str);
		printf("BEFORE: %s\n", argv[1]);
		printf("AFTER : %s\n", str);
	}
	return (0);
}
