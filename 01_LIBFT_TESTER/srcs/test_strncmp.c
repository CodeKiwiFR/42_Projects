/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:22:00 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 14:46:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_strncmp(void)
{
	int		cpt;
	int		my_res;
	int		lib_res;
	int		test_result;
	char	*s1;
	char	*s2;

	cpt = 1;
	print_test_intro("strncmp");

	// Test 1
	lib_res = strncmp("Hello", "Hello", 5);
	my_res = ft_strncmp("Hello", "Hello", 5);
	test_result = (lib_res == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 2
	lib_res = strncmp("Hello", "Hello", 0);
	my_res = ft_strncmp("Hello", "Hello", 0);
	test_result = (lib_res == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 3
	lib_res = strncmp("Hello", "Heldi", 3);
	my_res = ft_strncmp("Hello", "Heldi", 3);
	test_result = (lib_res == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 4
	lib_res = strncmp("Hello", "Heldi", 4);
	my_res = ft_strncmp("Hello", "Heldi", 4);
	test_result = (lib_res > 0 && my_res > 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 5
	lib_res = strncmp("Hel", "Hello", 4);
	my_res = ft_strncmp("Hel", "Hello", 4);
	test_result = (lib_res < 0 && my_res < 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 6
	s1 = "Hello";
	s2 = "";
	lib_res = strncmp(s1, s2, 50);
	my_res = ft_strncmp(s1, s2, 50);
	test_result = (lib_res > 0 && my_res > 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 7
	s1 = "";
	s2 = "Hello";
	lib_res = strncmp(s1, s2, 100);
	my_res = ft_strncmp(s1, s2, 100);
	test_result = (lib_res < 0 && my_res < 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 8
	lib_res = strncmp("", "", 5);
	my_res = ft_strncmp("", "", 5);
	test_result = (lib_res == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 9
	lib_res = strncmp("Hello", "Lol", 0);
	my_res = ft_strncmp("Hello", "Lol", 0);
	test_result = (lib_res == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 10
	lib_res = strncmp("Hello", "Aello", 6);
	my_res = ft_strncmp("Hello", "Aello", 6);
	test_result = (lib_res > 0 && my_res > 0);
	print_test_infos(cpt++, test_result, 1);
}
