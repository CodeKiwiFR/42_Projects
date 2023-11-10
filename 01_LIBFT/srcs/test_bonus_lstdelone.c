/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus_lstdelone.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 19:40:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_lstdelone(void)
{
	int		cpt;
	int		test_val;
	t_list	*lst;
	char	*str;

	cpt = 1;
	print_test_intro("(B) lstdelone");

	// Test 1
	str = strdup("HELLO");
	if (str == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		lst = ft_lstnew(str);
		if (lst == NULL)
		{
			free(str);
			print_red(" MALLOC ERROR ");
		}
		else
		{
			ft_lstdelone(lst, free);
			test_val = 1;
			print_test_infos(cpt++, test_val, 0);
		}
	}

	print_blue("Memory tests not provided => use Valgrind\n");
}
