/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 18:14:22 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_strtrim(void)
{
	int		cpt;
	int		test_val;
	char	*res;

	cpt = 1;
	print_test_intro("strtrim");
	 
	// Test 1
	res = ft_strtrim("   Hello   ", " ");
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "Hello") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 2
	res = ft_strtrim("   Hello   ", " oeHl");
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 3
	res = ft_strtrim("   Hello   ", "asdf");
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "   Hello   ") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 4
	res = ft_strtrim("   Hello   ", "Hello");
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "   Hello   ") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 5
	res = ft_strtrim("   Hello   ", NULL);
	test_val = (res == NULL);
	print_test_infos(cpt++, test_val, 0);

	// Test 6
	res = ft_strtrim(NULL, " ");
	test_val = (res == NULL);
	print_test_infos(cpt++, test_val, 0);

	// Test 7
	res = ft_strtrim("   Hello   ", " He");
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "llo") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 8
	res = ft_strtrim("   Hello   ", "");
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "   Hello   ") == 0);
		print_test_infos(cpt++, test_val, 1);
		free(res);
	}
}
