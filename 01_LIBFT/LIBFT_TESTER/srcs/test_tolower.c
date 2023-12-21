/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 14:21:31 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_tolower(void)
{
	int	cpt;
	int	lib_val;
	int	my_val;

	cpt = 1;
	print_test_intro("tolower");
	
	// Test 1
	lib_val = tolower('A');
	my_val = ft_tolower('A');
	print_test_infos(cpt++, lib_val == my_val, 0);
	
	// Test 2
	lib_val = tolower('Z');
	my_val = ft_tolower('Z');
	print_test_infos(cpt++, lib_val == my_val, 0);
	
	// Test 3
	lib_val = tolower('!');
	my_val = ft_tolower('!');
	print_test_infos(cpt++, lib_val == my_val, 0);
	
	// Test 4
	lib_val = tolower(0);
	my_val = ft_tolower(0);
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 5
	lib_val = tolower('a');
	my_val = ft_tolower('a');
	print_test_infos(cpt++, lib_val == my_val, 0);

	// Test 6
	lib_val = tolower('z' + 1);
	my_val = ft_tolower('z' + 1);
	print_test_infos(cpt++, lib_val == my_val, 0);
	
	// Test 5
	lib_val = tolower(200);
	my_val = ft_tolower(200);
	print_test_infos(cpt++, lib_val == my_val, 1);
}
