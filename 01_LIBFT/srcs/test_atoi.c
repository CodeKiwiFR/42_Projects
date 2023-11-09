/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:20:59 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 12:30:09 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_atoi(void)
{
	int		cpt;
	int		test_result;
	int		lib_res;
	int		my_res;
	char	*str;

	cpt = 1;
	print_test_intro("atoi");

	// Test 1
	str = "Hello";
	lib_res = atoi(str);
	my_res = ft_atoi(str);
	test_result = (lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 2
	str = "123";
	lib_res = atoi(str);
	my_res = ft_atoi(str);
	test_result = (lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 3
	str = "-257";
	lib_res = atoi(str);
	my_res = ft_atoi(str);
	test_result = (lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 4
	str = "    \t\n   +97";
	lib_res = atoi(str);
	my_res = ft_atoi(str);
	test_result = (lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 5
	str = "     +-98";
	lib_res = atoi(str);
	my_res = ft_atoi(str);
	test_result = (lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 6
	str = "-2147483648";
	lib_res = atoi(str);
	my_res = ft_atoi(str);
	test_result = (lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 7
	str = "2147483647";
	lib_res = atoi(str);
	my_res = ft_atoi(str);
	test_result = (lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 8
	str = "2147483648";
	lib_res = atoi(str);
	my_res = ft_atoi(str);
	test_result = (lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 9
	str = " +0 123";
	lib_res = atoi(str);
	my_res = ft_atoi(str);
	test_result = (lib_res == my_res);
	print_test_infos(cpt++, test_result, 1);

}
