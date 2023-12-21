/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:32 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 14:24:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_memmove(void)
{
	int		cpt;
	int		test_result;
	void	*ptr1;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;

	print_test_intro("memmove");
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
	bzero(ptr1, 10);
	bzero(ptr3, 10);
	memcpy(ptr1, "abcdefghi", 9);
	memcpy(ptr3, "abcdefghi", 9);

	// Test 0 (no overlap)
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char s2[] = {65, 66, 67, 68, 69, 0, 45};
	char s02[] = { 0,  0,  0,  0,  0,  0, 0};
	memmove(s0, s, 7);
	ft_memmove(s02, s2, 7);
	test_result = memcmp(s2, s02, 7);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 1 (no overlap)
	memmove(ptr2, ptr1, 3);
	ft_memmove(ptr4, ptr3, 3);
	test_result = memcmp(ptr1, ptr3, 10);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 2 (overlap)
	memcpy(ptr1, "abcdefghi", 9);
	memcpy(ptr3, "abcdefghi", 9);
	memmove(ptr2, ptr1, 5);
	ft_memmove(ptr4, ptr3, 5);
	test_result = memcmp(ptr1, ptr3, 10);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 3 (overlap other side)
	memcpy(ptr1, "abcdefghi", 9);
	memcpy(ptr3, "abcdefghi", 9);
	memmove(ptr1, ptr2, 5);
	ft_memmove(ptr3, ptr4, 5);
	test_result = memcmp(ptr1, ptr3, 10);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 4
	memmove(ptr2, "lol", 3);
	ft_memmove(ptr4, "lol", 3);
	test_result = memcmp(ptr1, ptr3, 10);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 5
	memmove(ptr1, "aaaaa", 5);
	ft_memmove(ptr3, "aaaaa", 5);
	test_result = memcmp(ptr1, ptr3, 10);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 6 (same memory address)
	memcpy(ptr1, "abcdefghi", 9);
	memcpy(ptr3, "abcdefghi", 9);
	ptr2 = ptr1;
	ptr4 = ptr3;
	memmove(ptr1, ptr2, 5);
	ft_memmove(ptr3, ptr4, 5);
	test_result = memcmp(ptr1, ptr3, 10);
	print_test_infos(cpt++, test_result == 0, 1);

	free(ptr1);
	free(ptr3);
}
