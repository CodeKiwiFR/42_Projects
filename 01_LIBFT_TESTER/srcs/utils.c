/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:07:14 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 18:18:47 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

static void	print_error(void)
{
	print_red("ERROR");
}

static void	print_ok(void)
{
	print_green("OK");
}

void	print_test_infos(int test_index, int test_success, int is_last)
{
	printf("test%d: ", test_index);
	if (test_success)
		print_ok();
	else
		print_error();
	if (is_last)
		printf("\n");
	else
		printf(" - ");
}

void	print_test_intro(char *func_name)
{
	printf("- %s():\t", func_name);
}

void	print_red(char *str)
{
	printf("\033[0;31m");
	printf("%s", str);
	printf("\033[0m");
}

void	print_green(char *str)
{
	printf("\033[0;32m");
	printf("%s", str);
	printf("\033[0m");
}

void	print_blue(char *str)
{
	printf("\033[0;34m");
	printf("%s", str);
	printf("\033[0m");
}
