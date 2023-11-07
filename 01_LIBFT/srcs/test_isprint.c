/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/07 21:12:37 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_isprint(void)
{
	int	cpt;
	int	lib_val;
	int	my_val;

	cpt = 1;
	print_test_intro("isprint");

	// Test 1
	lib_val = isprint('a');
	my_val = ft_isprint('a');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 2
	lib_val = isprint('0');
	my_val = ft_isprint('0');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 3
	lib_val = isprint(32);
	my_val = ft_isprint(32);
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 4
	lib_val = isprint('\n');
	my_val = ft_isprint('\n');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 5
	lib_val = isprint(128);
	my_val = ft_isprint(128);
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 6
	lib_val = isprint(251);
	my_val = ft_isprint(251);
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 7
	lib_val = isprint(31);
	my_val = ft_isprint(31);
	print_test_infos(cpt++, lib_val == my_val, 1);
}
