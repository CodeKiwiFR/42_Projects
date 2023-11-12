/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:21:39 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 11:59:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_memcmp(void)
{
	int		cpt;
	int		my_res;
	int		lib_res;
	int		test_result;
	char	*s1;
	char	*s2;

	cpt = 1;
	print_test_intro("memcmp");

	// Test 1
	lib_res = memcmp("Hello", "Hello", 5);
	my_res = ft_memcmp("Hello", "Hello", 5);
	test_result = (lib_res == 0 && my_res == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 2
	lib_res = memcmp("Hello", "Hello", 0);
	my_res = ft_memcmp("Hello", "Hello", 0);
	test_result = (lib_res == 0 && my_res == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 3
	lib_res = memcmp("Hello", "Heldi", 3);
	my_res = ft_memcmp("Hello", "Heldi", 3);
	test_result = (lib_res == 0 && my_res == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 4
	lib_res = memcmp("Hello", "Helci", 4);
	my_res = ft_memcmp("Hello", "Helci", 4);
	test_result = (lib_res > 0 && my_res > 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 5
	lib_res = memcmp("Hello", "Hel", 3);
	my_res = ft_memcmp("Hello", "Hel", 3);
	test_result = (lib_res == 0 && my_res == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 6
	s1 = "Hello";
	s2 = "";
	lib_res = memcmp(s1, s2, 1);
	my_res = ft_memcmp(s1, s2, 1);
	test_result = (lib_res > 0 && my_res > 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 7
	lib_res = memcmp("", "Hello", 1);
	my_res = ft_memcmp("", "Hello", 1);
	test_result = (lib_res < 0 && my_res < 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 8
	lib_res = memcmp("", "", 1);
	my_res = ft_memcmp("", "", 1);
	test_result = (lib_res == 0 && my_res == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 9
	lib_res = memcmp("Hello", "Lol", 0);
	my_res = ft_memcmp("Hello", "Lol", 0);
	test_result = (lib_res == 0 && my_res == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 10
	lib_res = memcmp("Hello", "Zelci", 4);
	my_res = ft_memcmp("Hello", "Zelci", 4);
	test_result = (lib_res < 0 && my_res < 0);
	print_test_infos(cpt++, test_result, 1);
}
