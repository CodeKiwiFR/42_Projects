/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 19:26:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

/*
static void	display_result(char **res)
{
	size_t	i;

	if (res == NULL)
		return ;
	i = 0;
	printf("RES: [");
	while (res[i] != NULL)
	{
		printf("\"%s\"", res[i]);
		if (res[i + 1] != NULL)
			printf(" - ");
		i++;
	}
	printf("]\n");
}
*/

void	test_split(void)
{
	int		cpt;
	int		test_val;
	char	**res;
	size_t	size;
	size_t	i;

	cpt = 1;
	print_test_intro("split");
	 
	// Test 1
	res = ft_split("   Hello   World !" , ' ');
	if (res == NULL)
		printf("ERROR ");
	else
	{
		size = 0;
		while (res[size] != NULL)
			size++;
		test_val = (size == 3) && (strcmp("Hello", res[0]) == 0) && (strcmp("World", res[1]) == 0) && (strcmp("!", res[2]) == 0);
		print_test_infos(cpt++, test_val, 0);
		i = 0;
		while (i < size)
			free(res[i++]);
		free(res);
	}
	 
	// Test 2
	res = ft_split("    aaa     bbb      c    " , ' ');
	if (res == NULL)
		printf("ERROR ");
	else
	{
		size = 0;
		while (res[size] != NULL)
			size++;
		test_val = (size == 3) && (strcmp("aaa", res[0]) == 0) && (strcmp("bbb", res[1]) == 0) && (strcmp("c", res[2]) == 0);
		print_test_infos(cpt++, test_val, 0);
		i = 0;
		while (i < size)
			free(res[i++]);
		free(res);
	}
	 
	// Test 3
	res = ft_split("" , 'o');
	if (res == NULL)
		printf("ERROR ");
	else
	{
		size = 0;
		while (res[size] != NULL)
			size++;
		test_val = (size == 0);
		print_test_infos(cpt++, test_val, 0);
		i = 0;
		while (i < size)
			free(res[i++]);
		free(res);
	}
	 
	// Test 4
	res = ft_split("oooooooooooooooooooooo" , 'o');
	if (res == NULL)
		printf("ERROR ");
	else
	{
		size = 0;
		while (res[size] != NULL)
			size++;
		test_val = (size == 0);
		print_test_infos(cpt++, test_val, 0);
		i = 0;
		while (i < size)
			free(res[i++]);
		free(res);
	}
	 
	// Test 5
	res = ft_split("Heeello Worlde!!!eeewhattimeisit" , 'e');
	if (res == NULL)
		printf("ERROR ");
	else
	{
		size = 0;
		while (res[size] != NULL)
			size++;
		test_val =
			(size == 5) && (strcmp("H", res[0]) == 0) && (strcmp("llo World", res[1]) == 0)
			&& (strcmp("!!!", res[2]) == 0) && (strcmp("whattim", res[3]) == 0) && (strcmp("isit", res[4]) == 0);
		print_test_infos(cpt++, test_val, 0);
		i = 0;
		while (i < size)
			free(res[i++]);
		free(res);
	}
	 
	// Test 6
	res = ft_split("   Hello   World !" , 'p');
	if (res == NULL)
		printf("ERROR ");
	else
	{
		size = 0;
		while (res[size] != NULL)
			size++;
		test_val = (size == 1) && (strcmp("   Hello   World !", res[0]) == 0);
		print_test_infos(cpt++, test_val, 1);
		i = 0;
		while (i < size)
			free(res[i++]);
		free(res);
	}

}
