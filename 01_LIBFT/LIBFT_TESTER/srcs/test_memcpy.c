/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:32 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 09:55:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_memcpy(void)
{
	int		cpt;
	int		test_result;
	void	*ptr1;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;

	print_test_intro("memcpy");
	cpt = 1;
	ptr1 = malloc(10 * sizeof(char));
	if (!ptr1)
	{
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	ptr3 = malloc(10 * sizeof(char));
	if (!ptr3)
	{
		free(ptr1);
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	ptr2 = ptr1 + 3;
	ptr4 = ptr3 + 3;

	// Test 1
	bzero(ptr1, 10);
	bzero(ptr3, 10);
	memcpy(ptr1, "abcdefghi", 9);
	ft_memcpy(ptr3, "abcdefghi", 9);
	test_result = memcmp(ptr1, ptr3, 10);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 2
	memcpy(ptr2, "lol", 3);
	ft_memcpy(ptr4, "lol", 3);
	test_result = memcmp(ptr1, ptr3, 10);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 3
	memcpy(ptr1, "aaaaa", 5);
	ft_memcpy(ptr3, "aaaaa", 5);
	test_result = memcmp(ptr1, ptr3, 10);
	print_test_infos(cpt++, test_result == 0, 1);

	free(ptr1);
	free(ptr3);
}
