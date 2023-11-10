/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 10:19:06 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_itoa(void)
{
	int		cpt;
	int		test_val;
	char	*nb_str;

	cpt = 1;
	print_test_intro("itoa");

	// Test 1
	nb_str = ft_itoa(0);
	if (nb_str == NULL)
		printf(" ERROR ");
	else
	{
		test_val = (memcmp(nb_str, "0", 2) == 0);
		print_test_infos(cpt++, test_val, 0);
		free(nb_str);
	}

	// Test 2
	nb_str = ft_itoa(-2147483648);
	if (nb_str == NULL)
		printf(" ERROR ");
	else
	{
		test_val = (memcmp(nb_str, "-2147483648", 11) == 0);
		print_test_infos(cpt++, test_val, 0);
		free(nb_str);
	}

	// Test 3
	nb_str = ft_itoa(2147483647);
	if (nb_str == NULL)
		printf(" ERROR ");
	else
	{
		test_val = (memcmp(nb_str, "2147483647", 10) == 0);
		print_test_infos(cpt++, test_val, 0);
		free(nb_str);
	}

	// Test 4
	nb_str = ft_itoa(-1);
	if (nb_str == NULL)
		printf(" ERROR ");
	else
	{
		test_val = (memcmp(nb_str, "-1", 3) == 0);
		print_test_infos(cpt++, test_val, 0);
		free(nb_str);
	}

	// Test 5
	nb_str = ft_itoa(1);
	if (nb_str == NULL)
		printf(" ERROR ");
	else
	{
		test_val = (memcmp(nb_str, "1", 2) == 0);
		print_test_infos(cpt++, test_val, 0);
		free(nb_str);
	}

	// Test 6
	nb_str = ft_itoa(-127);
	if (nb_str == NULL)
		printf(" ERROR ");
	else
	{
		test_val = (memcmp(nb_str, "-127", 5) == 0);
		print_test_infos(cpt++, test_val, 0);
		free(nb_str);
	}

	// Test 7
	nb_str = ft_itoa(2048);
	if (nb_str == NULL)
		printf(" ERROR ");
	else
	{
		test_val = (memcmp(nb_str, "2048", 2) == 0);
		print_test_infos(cpt++, test_val, 1);
		free(nb_str);
	}

}
