/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:43:08 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/11 16:56:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	/*
	int		v1;
	int		v2;
	const char	*format = "%d %wy %wyHello World %s!%\n";

	v1 = ft_printf(format, 50, "MY STRING");
	v2 = printf(format, 50, "MY STRING");
	printf("V1: %d - V2: %d - LEN: %zu\n", v1, v2, ft_strlen(format));
	*/
	int     i;
    char    c;

    i = 0;
    c = -128;
    while (i < 255)
    {
        printf("%i: \"%c\"\n", i, c);
        printf("%i: \"%s\"\n", i, ft_ctoa(c));
        i++;
        c++;
    }
	return (0);
}
