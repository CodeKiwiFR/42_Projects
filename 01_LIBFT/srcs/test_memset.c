/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:32 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 11:26:37 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_memset(void)
{
	int		cpt;
	int		test_result;
	void	*ptr1;
	void	*ptr2;

	print_test_intro("memset");
	cpt = 1;
	ptr1 = malloc(10 * sizeof(char));
	if (!ptr1)
	{
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	ptr2 = malloc(10 * sizeof(char));
	if (!ptr2)
	{
		free(ptr1);
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}

	// Test 1
	ptr1 = memset(ptr1, 0, 10);
	ptr2 = ft_memset(ptr2, 0, 10);
	test_result = memcmp(ptr1, ptr2, 10);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 2
	ptr1 = memset(ptr1, 'a', 9);
	ptr2 = ft_memset(ptr2, 'a', 9);
	test_result = memcmp(ptr1, ptr2, 10);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 3
	ptr1 = memset(ptr1, 'b', 3);
	ptr2 = ft_memset(ptr2, 'b', 3);
	test_result = memcmp(ptr1, ptr2, 10);
	print_test_infos(cpt++, test_result == 0, 1);

	free(ptr1);
	free(ptr2);
}
