/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/11 11:06:13 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_isdigit(void)
{
	int	cpt;
	int	lib_val;
	int	my_val;
	int	test_val;

	cpt = 1;
	print_test_intro("isdigit");

	// Test 1
	lib_val = isdigit('a');
	my_val = ft_isdigit('a');
	test_val = (lib_val == 0 && my_val == 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 2
	lib_val = isdigit('0');
	my_val = ft_isdigit('0');
	test_val = (lib_val > 0 && my_val > 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 3
	lib_val = isdigit('5');
	my_val = ft_isdigit('5');
	test_val = (lib_val > 0 && my_val > 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 4
	lib_val = isdigit('9');
	my_val = ft_isdigit('9');
	test_val = (lib_val > 0 && my_val > 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 5
	lib_val = isdigit(11784);
	my_val = ft_isdigit(11784);
	test_val = (lib_val == 0 && my_val == 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 6
	lib_val = isdigit('?');
	my_val = ft_isdigit('?');
	test_val = (lib_val == 0 && my_val == 0);
	print_test_infos(cpt++, test_val, 0);

	// Test 7
	lib_val = isdigit('Z');
	my_val = ft_isdigit('Z');
	test_val = (lib_val == 0 && my_val == 0);
	print_test_infos(cpt++, test_val, 1);
}
