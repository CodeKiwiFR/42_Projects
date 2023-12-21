/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/13 12:47:28 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_substr(void)
{
	int		cpt;
	int		test_val;
	char	*res;

	cpt = 1;
	print_test_intro("substr");
	
	// Test 1
	res = ft_substr("abcdefghi", 0, 4);
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "abcd") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 2
	res = ft_substr("abcdefghi", 6, 4);
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "ghi") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 3
	res = ft_substr("abcdefghi", 15, 20);
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 4
	res = ft_substr("abcdefghi", 2, 100);
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "cdefghi") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 5
	res = ft_substr("abcdefghi", 0, 0);
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 6
	res = ft_substr("abcdefghi", 7, 50);
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "hi") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 7
	res = ft_substr(NULL, 7, 50);
	test_val = (res == NULL);
	print_test_infos(cpt++, test_val, 1);
}
