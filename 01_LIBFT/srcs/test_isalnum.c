/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/11 11:03:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_isalnum(void)
{
	int	cpt;
	int	lib_val;
	int	my_val;
	int	test_val;

	cpt = 1;
	print_test_intro("isalnum");
	
	// Test 1
	lib_val = isalnum('a');
	my_val = ft_isalnum('a');
	test_val = (lib_val > 0 && my_val > 0);
	print_test_infos(cpt++, test_val, 0);
	
	// Test 2
	lib_val = isalnum('0');
	my_val = ft_isalnum('0');
	test_val = (lib_val > 0 && my_val > 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 3
	lib_val = isalnum('5');
	my_val = ft_isalnum('5');
	test_val = (lib_val > 0 && my_val > 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 4
	lib_val = isalnum('9');
	my_val = ft_isalnum('9');
	test_val = (lib_val > 0 && my_val > 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 5
	lib_val = isalnum('\n');
	my_val = ft_isalnum('\n');
	test_val = (lib_val == 0 && my_val == 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 6
	lib_val = isalnum('?');
	my_val = ft_isalnum('?');
	test_val = (lib_val == 0 && my_val == 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 7
	lib_val = isalnum('Z');
	my_val = ft_isalnum('Z');
	test_val = (lib_val > 0 && my_val > 0);
	print_test_infos(cpt++, test_val, 1);
}
