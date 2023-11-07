/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/07 10:51:31 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_isdigit(void)
{
	int	cpt;
	int	lib_val;
	int	my_val;

	cpt = 1;
	print_test_intro("isdigit");
	lib_val = isdigit('a');
	my_val = ft_isdigit('a');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isdigit('0');
	my_val = ft_isdigit('0');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isdigit('5');
	my_val = ft_isdigit('5');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isdigit('9');
	my_val = ft_isdigit('9');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isdigit(11784);
	my_val = ft_isdigit(11784);
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isdigit('?');
	my_val = ft_isdigit('?');
	print_test_infos(cpt++, lib_val == my_val, 0);
	lib_val = isdigit('Z');
	my_val = ft_isdigit('Z');
	print_test_infos(cpt++, lib_val == my_val, 1);
}
