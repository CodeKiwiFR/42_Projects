/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus_lstclear.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 19:34:21 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_lstclear(void)
{
	int		cpt;
	int		test_val;
	t_list	*lst;
	t_list	*node;
	char	*str;
	char	*str2;

	cpt = 1;
	print_test_intro("(B) lstclear");

	// Test 1
	lst = NULL;
	str = strdup("Hello");
	if (str == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		str2 = strdup("World");
		if (str2 == NULL)
		{
			free(str);
			print_red(" MALLOC ERROR ");
		}
		else
		{
			node = ft_lstnew(str);
			if (node == NULL)
			{
				free(str);
				free(str2);
				print_red(" MALLOC ERROR ");
			}
			else
			{
				ft_lstadd_back(&lst, node);
				node = ft_lstnew(str2);
				if (node == NULL)
				{
					free(str);
					free(str2);
					ft_lstdelone(lst, free);
					print_red(" MALLOC ERROR ");
				}
				else
				{
					ft_lstadd_back(&lst, node);
					test_val = ((strcmp(lst->content, "Hello") == 0) && (strcmp((lst->next)->content, "World") == 0));
					ft_lstclear(&lst, free);
					test_val = (test_val && lst == NULL);
					print_test_infos(cpt++, test_val, 0);
				}
			}
		}
	}
	print_blue("Memory tests not provided => use Valgrind\n");
}
