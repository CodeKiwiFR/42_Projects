/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:21:50 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 17:38:10 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_calloc(void)
{
	int		test_result;
	int		cpt;
	void	*lib_ptr;
	void	*my_ptr;
	size_t	nmemb;
	size_t	size;

	cpt = 1;
	print_test_intro("calloc");

	// Test 1
	nmemb = 5;
	size = sizeof(int);
	lib_ptr = calloc(nmemb, size);
	if (!lib_ptr)
	{
		print_red("ERROR - CALLOC FAILED\n");
		exit(0);
	}
	my_ptr = ft_calloc(nmemb, size);
	if (!my_ptr)
	{
		free(lib_ptr);
		print_red("ERROR - CALLOC FAILED\n");
		exit(0);
	}
	test_result = memcmp(lib_ptr, my_ptr, nmemb * size) == 0;
	print_test_infos(cpt++, test_result, 0);
	free(lib_ptr);
	free(my_ptr);

	// Test 2
	nmemb = 5;
	size = sizeof(int *);
	lib_ptr = calloc(nmemb, size);
	if (!lib_ptr)
	{
		print_red("ERROR - CALLOC FAILED\n");
		exit(0);
	}
	my_ptr = ft_calloc(nmemb, size);
	if (!my_ptr)
	{
		free(lib_ptr);
		print_red("ERROR - CALLOC FAILED\n");
		exit(0);
	}
	test_result = memcmp(lib_ptr, my_ptr, nmemb * size) == 0;
	print_test_infos(cpt++, test_result, 0);
	free(lib_ptr);
	free(my_ptr);

	/*
	// Test 3
	nmemb = 0;
	size = sizeof(char);
	my_ptr = ft_calloc(nmemb, size);
	test_result = (my_ptr == NULL);
	print_test_infos(cpt++, test_result, 0);
	free(my_ptr);

	// Test 4
	nmemb = 12;
	size = 0;
	my_ptr = ft_calloc(nmemb, size);
	test_result = (my_ptr == NULL);
	print_test_infos(cpt++, test_result, 0);
	free(my_ptr);
	*/

	// Test 5
	nmemb = 3000000000;
	size = sizeof(char);
	my_ptr = ft_calloc(nmemb, size);
	test_result = (my_ptr == NULL);
	print_test_infos(cpt++, test_result, 1);
	free(my_ptr);
}
