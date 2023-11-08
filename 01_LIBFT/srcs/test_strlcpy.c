/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 12:23:15 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_strlcpy(void)
{
	int		cpt;
	int		lib_val;
	int		my_val;
	int		test_result;
	char	*dest;
	char	*dest2;

	cpt = 1;
	print_test_intro("strlcpy");
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
	lib_val = strlcpy(dest, "Hello", 6);
	my_val = ft_strlcpy(dest2, "Hello", 6);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);
	
	// Test 2
	lib_val = strlcpy(dest, "World", 1);
	my_val = ft_strlcpy(dest2, "World", 1);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 3
	lib_val = strlcpy(dest, "Hello", 20);
	my_val = ft_strlcpy(dest2, "Hello", 20);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 4
	lib_val = strlcpy(dest, "Hello", 3);
	my_val = ft_strlcpy(dest2, "Hello", 3);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 0);

	// Test 5
	lib_val = strlcpy(dest, "Hello", 0);
	my_val = ft_strlcpy(dest2, "Hello", 0);
	test_result = (lib_val == my_val) && (memcmp(dest, dest2, 50) == 0);
	print_test_infos(cpt++, test_result, 1);

	free(dest);
	free(dest2);
}
