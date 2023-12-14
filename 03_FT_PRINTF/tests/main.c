/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:43:08 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 14:02:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	/*
	int		v1;
	int		v2;
	const char	*format = "%d %u %wyHello%%%%% World %c!  %X   %\n";

	v1 = ft_printf(format, 50, (unsigned int)-1, 'a', -2147483648);
	v2 = printf(format, 50, (unsigned int)-1, 'a', -2147483648);
	printf("V1: %d - V2: %d - LEN: %zu\n", v1, v2, ft_strlen(format));
	*/
	int	v1;
	int	v2;

	v1 = ft_printf(" %c %c %c \n", 0, '1', '2');
	v2 = printf(" %c %c %c \n", 0, '1', '2');
	printf("V1: %d - V2: %d\n", v1, v2);

	return (0);
}
