/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 14:21:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_toupper(void)
{
	int	cpt;
	int	lib_val;
	int	my_val;

	cpt = 1;
	print_test_intro("toupper");
	
	// Test 1
	lib_val = toupper('a');
	my_val = ft_toupper('a');
	print_test_infos(cpt++, lib_val == my_val, 0);
	
	// Test 2
	lib_val = toupper('z');
	my_val = ft_toupper('z');
	print_test_infos(cpt++, lib_val == my_val, 0);
	
	// Test 3
	lib_val = toupper('!');
	my_val = ft_toupper('!');
	print_test_infos(cpt++, lib_val == my_val, 0);
	
	// Test 4
	lib_val = toupper(0);
	my_val = ft_toupper(0);
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 5
	lib_val = toupper('A');
	my_val = ft_toupper('A');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 6
	lib_val = toupper('z' + 1);
	my_val = ft_toupper('z' + 1);
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 5
	lib_val = toupper(200);
	my_val = ft_toupper(200);
	print_test_infos(cpt++, lib_val == my_val, 1);
}
