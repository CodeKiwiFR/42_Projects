/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus_lstadd_back.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 19:45:59 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_lstadd_back(void)
{
	int		cpt;
	int		test_val;
	t_list	*lst;
	t_list	*node;

	cpt = 1;
	print_test_intro("(B) lstadd_back");

	// Test 1
	lst = NULL;
	node = ft_lstnew("Hello");
	if (node == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		ft_lstadd_back(&lst, node);
		node = ft_lstnew("World");
		if (node == NULL)
		{
			free(lst);
			print_red(" MALLOC ERROR ");
		}
		else
		{
			ft_lstadd_back(&lst, node);
			test_val = ((strcmp(lst->content, "Hello") == 0) && (strcmp((lst->next)->content, "World") == 0));
			print_test_infos(cpt++, test_val, 1);
			free(lst->next);
			free(lst);
		}
	}
}
