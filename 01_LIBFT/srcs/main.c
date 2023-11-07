/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:32:06 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/07 14:42:07 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <stdio.h>

int	main(void)
{
	system("clear");
	printf("*******************\n");
	printf("**  LIBFT TESTS  **\n");
	printf("*******************\n\n");
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	printf("\n");
	test_strlen();
	test_memset();
	test_bzero();
	return (0);
}
