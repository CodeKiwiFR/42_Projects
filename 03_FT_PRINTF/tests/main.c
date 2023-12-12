/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:43:08 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/12 18:02:57 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	
	int		v1;
	int		v2;
	const char	*format = "%d %u %wyHello%%%%% World %c!%\n";

	v1 = ft_printf(format, 50, (unsigned int)-1, 'a');
	v2 = printf(format, 50, (unsigned int)-1, 'a');
	printf("V1: %d - V2: %d - LEN: %zu\n", v1, v2, ft_strlen(format));
	/*
	printf("\"%u\"\n", UINT_MAX);
	printf("\"%s\"\n", ft_ltoa(LONG_MIN));
	*/
	return (0);
}
