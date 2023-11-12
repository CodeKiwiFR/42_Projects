/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 17:42:28 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_strjoin(void)
{
	int		cpt;
	int		test_val;
	char	*res;

	cpt = 1;
	print_test_intro("strjoin");
	
	// Test 1
	res = ft_strjoin("Hello", " World!");
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "Hello World!") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}
	
	// Test 2
	res = ft_strjoin("", "YOUPI");
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "YOUPI") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}
	
	// Test 3
	res = ft_strjoin("Not Youpi", "");
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "Not Youpi") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}
	
	// Test 4
	res = ft_strjoin("", "");
	if (res == NULL)
		printf("ERROR\n\n");
	else
	{
		test_val = (strcmp(res, "") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 5
	res = ft_strjoin(NULL, "Hello");
	test_val = (res == NULL);
	print_test_infos(cpt++, test_val, 0);

	// Test 6
	res = ft_strjoin("Hello", NULL);
	test_val = (res == NULL);
	print_test_infos(cpt++, test_val, 1);
}
