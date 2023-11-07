/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/07 21:10:58 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_isascii(void)
{
	int	cpt;
	int	lib_val;
	int	my_val;

	cpt = 1;
	print_test_intro("isascii");

	// Test 1
	lib_val = isascii('a');
	my_val = ft_isascii('a');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 2
	lib_val = isascii('0');
	my_val = ft_isascii('0');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 3
	lib_val = isascii('5');
	my_val = ft_isascii('5');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 4
	lib_val = isascii('9');
	my_val = ft_isascii('9');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 5
	lib_val = isascii(255);
	my_val = ft_isascii(255);
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 6
	lib_val = isascii(0);
	my_val = ft_isascii(0);
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 7
	lib_val = isascii(128);
	my_val = ft_isascii(128);
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 8
	lib_val = isascii('?');
	my_val = ft_isascii('?');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 9
	lib_val = isascii(-1);
	my_val = ft_isascii(-1);
	print_test_infos(cpt++, lib_val == my_val, 1);
}
