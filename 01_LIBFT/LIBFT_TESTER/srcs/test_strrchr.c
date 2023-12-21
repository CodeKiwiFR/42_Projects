/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:22:12 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 10:14:42 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_strrchr(void)
{
	int		cpt;
	int		test_result;
	char	*lib_res;
	char	*my_res;
	char	*str;

	cpt = 1;
	print_test_intro("strrchr");

	// Test 1
	lib_res = strrchr("Hello", 'o');
	my_res = ft_strrchr("Hello", 'o');
	test_result = strcmp(lib_res, my_res) == 0;
	print_test_infos(cpt++, test_result, 0);

	// Test 2
	lib_res = strrchr("Hello World", 'o');
	my_res = ft_strrchr("Hello World", 'o');
	test_result = strcmp(lib_res, my_res) == 0;
	print_test_infos(cpt++, test_result, 0);

	// Test 3
	lib_res = strrchr("aaa aaa", 'o');
	my_res = ft_strrchr("aaa aaa", 'o');
	test_result = lib_res == NULL && my_res == NULL;
	print_test_infos(cpt++, test_result, 0);

	// Test 4
	lib_res = strrchr("o", 'o');
	my_res = ft_strrchr("o", 'o');
	test_result = strcmp(lib_res, my_res) == 0;
	print_test_infos(cpt++, test_result, 0);

	// Test 5
	str = "my string";
	lib_res = strrchr(str, 'i');
	my_res = ft_strrchr(str, 'i');
	test_result = (strcmp(lib_res, my_res) == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 6
	str = "my string";
	lib_res = strrchr(str, '?');
	my_res = ft_strrchr(str, '?');
	test_result = (lib_res == NULL && lib_res == my_res);
	
	// Test 7
	str = "More of letter -o of course";
	lib_res = strrchr(str, 'o');
	my_res = ft_strrchr(str, 'o');
	test_result = (strcmp(lib_res, my_res) == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 1);
}
