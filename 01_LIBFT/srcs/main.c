/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:32:06 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 09:31:32 by mhotting         ###   ########.fr       */
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
	test_memcpy();
	test_memmove();
	printf("\n");

	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	printf("\n");

	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	printf("\n");

	test_atoi();
	test_calloc();
	test_strdup();

	return (0);
}
