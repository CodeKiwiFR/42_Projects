/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:22:06 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 12:21:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_strnstr(void)
{
	int		cpt;
	int		test_result;
	char	*lib_res;
	char	*my_res;
	char	*s1;
	char	*s2;
	size_t	len;

	cpt = 1;
	print_test_intro("strnstr");

	// Test 1
	s1 = "Hello";
	s2 = "o";
	len = 5;
	lib_res = strnstr(s1, s2, len);
	my_res = ft_strnstr(s1, s2, len);
	test_result = (lib_res == my_res && strcmp(lib_res, my_res) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 2
	s1 = "Hello";
	s2 = "o";
	len = 4;
	lib_res = strnstr(s1, s2, len);
	my_res = ft_strnstr(s1, s2, len);
	test_result = (lib_res == my_res && lib_res == 0);
	print_test_infos(cpt++, test_result, 0);
	
	// Test 3
	s1 = "";
	s2 = "Lol";
	len = 5;
	lib_res = strnstr(s1, s2, len);
	my_res = ft_strnstr(s1, s2, len);
	test_result = (lib_res == my_res && lib_res == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 4
	s1 = "Hello";
	s2 = "";
	len = 5;
	lib_res = strnstr(s1, s2, len);
	my_res = ft_strnstr(s1, s2, len);
	test_result = (lib_res == my_res && strcmp(lib_res, my_res) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 5
	s1 = "Hello";
	s2 = "llo";
	len = 10;
	lib_res = strnstr(s1, s2, len);
	my_res = ft_strnstr(s1, s2, len);
	test_result = (lib_res == my_res && strcmp(lib_res, my_res) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 6
	s1 = "Hello Hell Hel He H   ";
	s2 = "He";
	len = 50;
	lib_res = strnstr(s1, s2, len);
	my_res = ft_strnstr(s1, s2, len);
	test_result = (lib_res == my_res && strcmp(lib_res, my_res) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 7
	s1 = "Bonjour Bonjour";
	s2 = "our";
	len = 3;
	lib_res = strnstr(s1, s2, len);
	my_res = ft_strnstr(s1, s2, len);
	test_result = (lib_res == my_res && lib_res == 0);
	print_test_infos(cpt++, test_result, 1);
}
