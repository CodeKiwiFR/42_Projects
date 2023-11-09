/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:21:50 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 15:02:47 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_strdup(void)
{
	char	*s1;
	char	*s2;
	char	*str;
	int		cpt;
	int		test_result;

	cpt = 1;
	print_test_intro("strdup");

	// Test 1
	str = "Hello";
	s1 = strdup(str);
	if (!s1)
	{
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	s2 = ft_strdup(str);
	if (!s2)
	{
		free(s1);
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	test_result = memcmp(s1, s2, ft_strlen(str) + 1) == 0;
	print_test_infos(cpt++, test_result, 0);
	free(s1);
	free(s2);

	// Test 2
	str = "Hello World !";
	s1 = strdup(str);
	if (!s1)
	{
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	s2 = ft_strdup(str);
	if (!s2)
	{
		free(s1);
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	test_result = memcmp(s1, s2, ft_strlen(str) + 1) == 0;
	print_test_infos(cpt++, test_result, 0);
	free(s1);
	free(s2);

	// Test 3
	str = "";
	s1 = strdup(str);
	if (!s1)
	{
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	s2 = ft_strdup(str);
	if (!s2)
	{
		free(s1);
		print_red("ERROR - MALLOC FAILED\n");
		exit(0);
	}
	test_result = memcmp(s1, s2, ft_strlen(str) + 1) == 0;
	print_test_infos(cpt++, test_result, 1);
	free(s1);
	free(s2);
}
