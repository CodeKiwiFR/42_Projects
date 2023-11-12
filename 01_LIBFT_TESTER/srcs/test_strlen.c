/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/07 21:14:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_strlen(void)
{
	int	cpt;
	int	lib_val;
	int	my_val;

	cpt = 1;
	print_test_intro("strlen");

	// Test 1
	lib_val = strlen("");
	my_val = ft_strlen("");
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 2
	lib_val = strlen("Hello World!");
	my_val = ft_strlen("Hello World!");
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 3
	lib_val = strlen("b");
	my_val = ft_strlen("b");
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 4
	lib_val = strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	my_val = ft_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	print_test_infos(cpt++, lib_val == my_val, 1);
}
