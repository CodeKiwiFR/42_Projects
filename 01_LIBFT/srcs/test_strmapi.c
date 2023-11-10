/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 18:21:55 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

static char	my_toupperi(unsigned int i, char c)
{
	if (i > 0)
		return (ft_toupper(c));
	return (ft_toupper(c));
}

void	test_strmapi(void)
{
	int		cpt;
	int		test_val;
	char	*res;

	cpt = 1;
	print_test_intro("strmapi");

	// Test 1
	res = ft_strmapi("bonjour", my_toupperi);
	if (res == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		test_val = (strcmp(res, "BONJOUR") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 2
	res = ft_strmapi("", my_toupperi);
	if (res == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		test_val = (strcmp(res, "") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 3
	res = ft_strmapi("HELLO", my_toupperi);
	if (res == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		test_val = (strcmp(res, "HELLO") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(res);
	}

	// Test 4
	res = ft_strmapi(NULL, my_toupperi);
	test_val = (res == NULL);
	print_test_infos(cpt++, test_val, 0);

	// Test 5
	res = ft_strmapi("WOrld", NULL);
	test_val = (res == NULL);
	print_test_infos(cpt++, test_val, 0);

	// Test 6
	res = ft_strmapi("World", my_toupperi);
	if (res == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		test_val = (strcmp(res, "WORLD") == 0);
		print_test_infos(cpt++, test_val, 1);
		free(res);
	}
}
