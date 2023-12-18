/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:43:08 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/18 14:41:09 by mhotting         ###   ########.fr       */
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

	/*
	v1 = ft_printf("\"%c\"\n", '0');
	v2 = printf("\"%c\"\n", '0');
	*/

	v1 = ft_printf("\"%10.5+.5d\"\n", 42);
	v2 = printf("\"%10.5+.5d\"\n", 42);
	printf("V1: %d - V2: %d\n", v1, v2);

	/*
	t_input_format format_info;
	input_format_get_info(&format_info, "%0+- 10.5c", 6);
	*/

	/*
	char	*test = "Hello";

	printf("\"%s\"\n", test);
	char	*test2 = ft_append_chars(test, 'c', 10);
	printf("\"%s\"\n", test2);
	printf("\"%zu\"\n", ft_strlen(test2));
	*/
	return (0);
}
