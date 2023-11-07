/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/07 10:53:07 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_isalpha(void)
{
	int	cpt;
	int	lib_val;
	int	my_val;

	cpt = 1;
	print_test_intro("isalpha");
	lib_val = isalpha('a');
	my_val = ft_isalpha('a');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isalpha('0');
	my_val = ft_isalpha('0');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isalpha('9');
	my_val = ft_isalpha('9');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isalpha('A');
	my_val = ft_isalpha('A');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isalpha('Z');
	my_val = ft_isalpha('Z');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isalpha('z');
	my_val = ft_isalpha('z');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isalpha('?');
	my_val = ft_isalpha('?');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isalpha(255);
	my_val = ft_isalpha(255);
	print_test_infos(cpt++, lib_val == my_val, 1);
}
