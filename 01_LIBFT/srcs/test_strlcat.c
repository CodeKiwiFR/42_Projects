/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 14:01:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_strlcat(void)
{
	int		cpt;
	int		lib_val;
	int		my_val;
	int		test_result;
	char	*dest;
	char	*dest2;

	cpt = 1;
	print_test_intro("strlcat");
	dest = (char *)malloc(50 * sizeof(char));
	if (!dest)
	{
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	dest2 = (char *)malloc(50 * sizeof(char));
	if (!dest2)
	{
		free(dest);
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	bzero((void *)dest, 50);
	bzero((void *)dest2, 50);

	// Test 1
	lib_val = strlcat(dest, "Hello", 6);
	my_val = ft_strlcat(dest2, "Hello", 6);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);
	
	// Test 2
	lib_val = strlcat(dest, "Worl", 1);
	my_val = ft_strlcat(dest2, "Worl", 1);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 3
	lib_val = strlcat(dest, "Worldi", 5);
	my_val = ft_strlcat(dest2, "Worldi", 5);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);
	
	// Test 4
	lib_val = strlcat(dest, "He", 20);
	my_val = ft_strlcat(dest2, "He", 20);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 5
	lib_val = strlcat(dest, "Helloooo", 3);
	my_val = ft_strlcat(dest2, "Helloooo", 3);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 6
	lib_val = strlcat(dest, "Hello World", 0);
	my_val = ft_strlcat(dest2, "Hello World", 0);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 7
	lib_val = strlcat(dest, "Hello World", 50);
	my_val = ft_strlcat(dest2, "Hello World", 50);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 8
	lib_val = strlcat(dest, "", 50);
	my_val = ft_strlcat(dest2, "", 50);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 9
	lib_val = strlcat(dest, "", 1);
	my_val = ft_strlcat(dest2, "", 1);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 1);

	free(dest);
	free(dest2);
}
