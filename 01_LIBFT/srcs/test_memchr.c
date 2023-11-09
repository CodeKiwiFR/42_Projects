/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:21:30 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 10:19:34 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_memchr(void)
{
	int		cpt;
	int		test_result;
	char	*lib_res;
	char	*my_res;
	char	*str;

	cpt = 1;
	print_test_intro("memchr");

	// Test 1
	lib_res = memchr("Hello", 'o', 6);
	my_res = ft_memchr("Hello", 'o', 6);
	test_result = strcmp(lib_res, my_res) == 0;
	print_test_infos(cpt++, test_result, 0);

	// Test 2
	lib_res = memchr("Hello World", 'o', 12);
	my_res = ft_memchr("Hello World", 'o', 12);
	test_result = strcmp(lib_res, my_res) == 0;
	print_test_infos(cpt++, test_result, 0);

	// Test 3
	lib_res = memchr("aaa aaa", 'o', 8);
	my_res = ft_memchr("aaa aaa", 'o', 8);
	test_result = lib_res == NULL && my_res == NULL;
	print_test_infos(cpt++, test_result, 0);

	// Test 4
	lib_res = memchr("o", 'o', 2);
	my_res = ft_memchr("o", 'o', 2);
	test_result = strcmp(lib_res, my_res) == 0;
	print_test_infos(cpt++, test_result, 0);

	// Test 5
	str = "my string";
	lib_res = memchr(str, 'i', 10);
	my_res = ft_memchr(str, 'i', 10);
	test_result = (strcmp(lib_res, my_res) == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 0);

	// Test 6
	str = "my string";
	lib_res = memchr(str, '?', 10);
	my_res = ft_memchr(str, '?', 10);
	test_result = (lib_res == NULL && lib_res == my_res);
	
	// Test 7
	str = "More of letter -o of course";
	lib_res = memchr(str, 'o', ft_strlen(str) + 1);
	my_res = ft_memchr(str, 'o', ft_strlen(str) + 1);
	test_result = (strcmp(lib_res, my_res) == 0 && lib_res == my_res);
	print_test_infos(cpt++, test_result, 1);
}
