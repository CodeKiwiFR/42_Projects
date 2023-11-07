/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/07 21:54:18 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_isalnum(void)
{
	int	cpt;
	int	lib_val;
	int	my_val;

	cpt = 1;
	print_test_intro("isalnum");
	
	// Test 1
	lib_val = isalnum('a');
	my_val = ft_isalnum('a');
	print_test_infos(cpt++, lib_val == my_val, 0);
	
	// Test 2
	lib_val = isalnum('0');
	my_val = ft_isalnum('0');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 3
	lib_val = isalnum('5');
	my_val = ft_isalnum('5');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 4
	lib_val = isalnum('9');
	my_val = ft_isalnum('9');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 5
	lib_val = isalnum('\n');
	my_val = ft_isalnum('\n');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 6
	lib_val = isalnum('?');
	my_val = ft_isalnum('?');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 7
	lib_val = isalnum('Z');
	my_val = ft_isalnum('Z');
	print_test_infos(cpt++, lib_val == my_val, 1);
}
