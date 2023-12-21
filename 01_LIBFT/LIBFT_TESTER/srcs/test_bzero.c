/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:32 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 18:05:31 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_bzero(void)
{
	int		cpt;
	int		test_result;
	void	*ptr1;
	void	*ptr2;

	print_test_intro("bzero");
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
	bzero(ptr1, 5);
	ft_bzero(ptr2, 5);
	test_result = memcmp(ptr1, ptr2, 5);
	print_test_infos(cpt++, test_result == 0, 0);

	// Test 2
	bzero(ptr1, 10);
	ft_bzero(ptr2, 10);
	test_result = memcmp(ptr1, ptr2, 10);
	print_test_infos(cpt++, test_result == 0, 1);

	free(ptr1);
	free(ptr2);
}
