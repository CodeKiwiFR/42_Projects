/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:43:08 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/19 14:34:45 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define TEST(S, A, B, C, D) str = S;	printf("TEST: %s", str); if (printf(str, A, B, C, D) != ft_printf(str, A, B, C, D)) { printf("\033[0;31m"); printf("ERROR\n\n"); printf("\033[0m"); nb_err++; } else { printf("\033[0;32m"); printf("Returned values OK\n\n"); printf("\033[0m"); }

#define STR(S) "\"" S "\"\n"


void	print_intro_test(char *intro)
{
	system("clear");
	printf("\e[1m");
	printf("\n********************\n");
	printf("* TESTS: %-9s *\n", intro);
	printf("********************\n\n");
	printf("\e[m");
}

void	pause_tests(size_t nb_err)
{
	if (nb_err > 0)
	{
		printf("\033[0;31m");
		printf("NB_ERRORS: %zu\n", nb_err);
		printf("\033[0m");
	}
	else
	{
		printf("\033[0;32m");
		printf("NB_ERRORS: %zu\n", nb_err);
		printf("\033[0m");
	}

	printf("Press ENTER to run next tests...");
	while (getchar() != '\n');
}

int	main(void)
{
	size_t	nb_err;
	char	*str;

	/*
	 * Mendatory
	 */

	// Tests %c
	nb_err = 0;
	print_intro_test("%c");
	TEST(STR("%c"), 'c', 0, 0, 0)
	TEST(STR("%c %c"), 'c', 'a', 0, 0)
	TEST(STR("%c %c"), 0, 'a', 0, 0)
	TEST(STR("%c %c"), 0, 1, 0, 0)
	TEST(STR("%c %c %c"), '0', 1, '2', 0)
	TEST(STR("%c %c %c"), '0', '1', '2', 0)
	TEST(STR("%c %c %c %c"), 1, 2, 3, 4)
	pause_tests(nb_err);
	
	// Tests %d %i
	nb_err = 0;
	print_intro_test("%d %i");
	TEST(STR("%d"), 0, 0, 0, 0)
	TEST(STR("%i"), 0, 0, 0, 0)
	TEST(STR("%d %d"), INT_MIN, INT_MAX, 0, 0)
	TEST(STR("%i %i"), INT_MIN, INT_MAX, 0, 0)
	TEST(STR("%d %d %d %d"), 1, 10, 100, 1000)
	TEST(STR("%i %i %i %i"), 1, 10, 100, 1000)
	TEST(STR("%d %d %d %d"), -1, -10, -100, -1000)
	TEST(STR("%i %i %i %i"), -1, -10, -100, -1000)
	TEST(STR("%d %d %d %d"), UINT_MAX, LONG_MAX, LONG_MIN, ULONG_MAX)
	TEST(STR("%i %i %i %i"), UINT_MAX, LONG_MAX, LONG_MIN, ULONG_MAX)
	TEST(STR("%d"), -485698, 0, 0, 0)
	TEST(STR("%i"), -485698, 0, 0, 0)
	pause_tests(nb_err);
	
	// Tests %u
	nb_err = 0;
	print_intro_test("%u");
	TEST(STR("%u"), 0, 0, 0, 0)
	TEST(STR("%u"), -1, 0, 0, 0)
	TEST(STR("%u"), 9, 0, 0, 0)
	TEST(STR("%u"), 10, 0, 0, 0)
	TEST(STR("%u"), 100, 0, 0, 0)
	TEST(STR("%u"), 1000, 0, 0, 0)
	TEST(STR("%u"), 9999, 0, 0, 0)
	TEST(STR("%u %u %u %u"), INT_MAX, UINT_MAX, LONG_MAX, ULONG_MAX)
	TEST(STR("%u %u %u %u"), INT_MIN, 0, LONG_MIN, 0)
	pause_tests(nb_err);
	
	// Tests %x %X
	nb_err = 0;
	print_intro_test("%x %X");
	TEST(STR("%x"), 0, 0, 0, 0)
	TEST(STR("%X"), 0, 0, 0, 0)
	TEST(STR("%x"), 1, 0, 0, 0)
	TEST(STR("%X"), 1, 0, 0, 0)
	TEST(STR("%x"), 42, 0, 0, 0)
	TEST(STR("%X"), 42, 0, 0, 0)
	TEST(STR("%x"), 99, 0, 0, 0)
	TEST(STR("%X"), 99, 0, 0, 0)
	TEST(STR("%x"), 100, 0, 0, 0)
	TEST(STR("%X"), 100, 0, 0, 0)
	TEST(STR("%x"), -42, 0, 0, 0)
	TEST(STR("%X"), -42, 0, 0, 0)
	TEST(STR("%x"), -99, 0, 0, 0)
	TEST(STR("%X"), -99, 0, 0, 0)
	TEST(STR("%x"), -100, 0, 0, 0)
	TEST(STR("%X"), -100, 0, 0, 0)
	TEST(STR("%x %x %x %x"), INT_MAX, UINT_MAX, LONG_MAX, ULONG_MAX)
	TEST(STR("%X %X %X %X"), INT_MAX, UINT_MAX, LONG_MAX, ULONG_MAX)
	TEST(STR("%x %x"), INT_MIN, LONG_MIN, 0, 0)
	TEST(STR("%X %X"), INT_MIN, LONG_MIN, 0, 0)
	pause_tests(nb_err);
	
	// Tests %s
	nb_err = 0;
	print_intro_test("%s");
	TEST(STR("%s"), "HELLO WORLD!", 0, 0, 0)
	TEST(STR("%s"), NULL, 0, 0, 0)
	TEST(STR("%s"), "", 0, 0, 0)
	TEST(STR("%s %s %s"), "", NULL, "HELLO", 0)
	TEST(STR("%s %s %s %s"), " - ", "...", "0123456789//\\%", "NULL")
	TEST(STR("%s %s %s %s"), "\t\t", "...", "\\\"lol\"'''", NULL)
	pause_tests(nb_err);
	
	// Tests %p
	nb_err = 0;
	print_intro_test("%p");
	TEST(STR("%p"), 0, 0, 0, 0)
	TEST(STR("%p"), -1, 0, 0, 0)
	TEST(STR("%p"), 1, 0, 0, 0)
	TEST(STR("%p"), 42, 0, 0, 0)
	TEST(STR("%p"), 16, 0, 0, 0)
	TEST(STR("%p"), 255, 0, 0, 0)
	TEST(STR("%p %p %p %p"), INT_MIN, LONG_MIN, NULL, 0)
	TEST(STR("%p %p %p %p"), INT_MAX, UINT_MAX, LONG_MAX, ULONG_MAX)
	pause_tests(nb_err);
	
	// Tests %%
	nb_err = 0;
	print_intro_test("%%");
	TEST(STR("%%%%"), 0, 0, 0, 0)
	TEST(STR("%"), 0, 0, 0, 0)
	TEST(STR("%%"), 0, 0, 0, 0)
	TEST(STR("%%%%%%%%%%"), 0, 0, 0, 0)
	TEST(STR("%%%%%%%%%"), 0, 0, 0, 0)
	TEST(STR("%%%%%%%%%%%%%%%%%"), 0, 0, 0, 0)
	pause_tests(nb_err);
	
	// Mix
	nb_err = 0;
	print_intro_test("Mix");
	TEST(STR("%%%c%%%s%%%d%%%i"), 'A', "42", 42, 0)
	TEST(STR("%%%u%%%x%%%X%%%%"), 42, 42, 42, 0)
	TEST(STR("%%%c%%%s%%%d%%%i"), 0, "HELLO", 123, -123)
	TEST(STR("% % %p % % %s % % % d % % %i"), NULL, NULL, -789, 0)
	pause_tests(nb_err);

	return (0);
}
