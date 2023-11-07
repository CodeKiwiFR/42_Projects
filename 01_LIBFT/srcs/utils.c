/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:07:14 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/07 10:29:08 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

static void	print_error(void)
{
	printf("\033[0;31mERROR\033[0m");
}

static void	print_ok(void)
{
	printf("\033[0;32mOK\033[0m");
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
	printf("- %s(): ", func_name);
}
