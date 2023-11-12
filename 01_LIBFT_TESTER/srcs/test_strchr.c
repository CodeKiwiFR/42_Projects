/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:21:50 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 10:12:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_strchr(void)
{
	int		cpt;
	int		test_result;
	char	*lib_res;
	char	*my_res;
	char	*str;

	cpt = 1;
	print_test_intro("strchr");

	// Test 1
	lib_res = strchr("Hello", 'o');
	my_res = ft_strchr("Hello", 'o');
	test_result = strcmp(lib_res, my_res) == 0;
	print_test_infos(cpt++, test_result, 0);

	// Test 2
	lib_res = strchr("Hello World", 'o');
	my_res = ft_strchr("Hello World", 'o');
	test_result = strcmp(lib_res, my_res) == 0;
	print_test_infos(cpt++, test_result, 0);

	// Test 3
	lib_res = strchr("aaa aaa", 'o');
	my_res = ft_strchr("aaa aaa", 'o');
	test_result = lib_res == NULL && my_res == NULL;
	print_test_infos(cpt++, test_result, 0);

	// Test 4
	lib_res = strchr("o", 'o');
	my_res = ft_strchr("o", 'o');
	test_result = strcmp(lib_res, my_res) == 0;
	print_test_infos(cpt++, test_result, 0);

	// Test 5
	str = "my string";
	lib_res = strchr(str, 'i');
	my_res = ft_strchr(str, 'i');
	test_result = (strcmp(lib_res, my_res) == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 6
	str = "my string";
	lib_res = strchr(str, '?');
	my_res = ft_strchr(str, '?');
	test_result = (lib_res == NULL && lib_res == my_res);
	
	// Test 7
	str = "More of letter -o of course";
	lib_res = strchr(str, 'o');
	my_res = ft_strchr(str, 'o');
	test_result = (strcmp(lib_res, my_res) == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 1);
}
