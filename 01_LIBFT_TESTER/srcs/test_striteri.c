/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/12 00:48:50 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

static void	my_toloweri(unsigned int i, char *str)
{
	if (i > 0)
		*str = ft_tolower(*str);
	*str = ft_tolower(*str);
}


void	test_striteri(void)
{
	int	cpt;
	int	test_val;
	char	*str;

	cpt = 1;
	print_test_intro("striteri");

	// Test 1
	str = strdup("BONJOUR");
	if (str == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		ft_striteri(str, my_toloweri);
		test_val = (strcmp(str, "bonjour") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(str);
	}

	// Test 2
	str = strdup("BONJOUR");
	if (str == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		ft_striteri(NULL, my_toloweri);
		test_val = (strcmp(str, "BONJOUR") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(str);
	}

	// Test 3
	str = strdup("BONJOUR");
	if (str == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		ft_striteri(str, NULL);
		test_val = (strcmp(str, "BONJOUR") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(str);
	}

	// Test 4
	str = strdup("");
	if (str == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		ft_striteri(str, my_toloweri);
		test_val = (strcmp(str, "") == 0);
		print_test_infos(cpt++, test_val, 0);
		free(str);
	}

	// Test 5
	str = strdup("bOnJoUr");
	if (str == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		ft_striteri(str, my_toloweri);
		test_val = (strcmp(str, "bonjour") == 0);
		print_test_infos(cpt++, test_val, 1);
		free(str);
	}

}
