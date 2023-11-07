/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/07 10:23:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_isalpha(void)
{
	int	lib_val;
	int	my_val;

	print_test_intro("isalpha");
	lib_val = isalpha('a');
	my_val = ft_isalpha('a');
	
	print_test_infos(1, lib_val == my_val, 0);
	lib_val = isalpha('0');
	my_val = ft_isalpha('0');
	print_test_infos(2, lib_val == my_val, 0);
	lib_val = isalpha(255);
	my_val = ft_isalpha(255);
	print_test_infos(3, lib_val == my_val, 0);
	lib_val = isalpha('A');
	my_val = ft_isalpha('A');
	print_test_infos(4, lib_val == my_val, 0);
	lib_val = isalpha('Z');
	my_val = ft_isalpha('Z');
	print_test_infos(5, lib_val == my_val, 1);
}
