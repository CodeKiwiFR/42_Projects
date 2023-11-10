/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus_lstnew.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 16:31:24 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_lstnew(void)
{
	int		cpt;
	int		test_val;
	t_list	*list;
	char	*content;

	cpt = 1;
	print_test_intro("(B) lstnew ");

	// Test 1
	content = strdup("Hello");
	if (content == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		list = ft_lstnew(content);
		if (list == NULL)
			print_red(" MALLOC ERROR ");
		else
		{
			test_val = (list->next == NULL && (strcmp(list->content, "Hello") == 0));
			print_test_infos(cpt++, test_val, 0);
			free(list);
		}
		free(content);
	}

	// Test 2
	content = NULL;
	list = ft_lstnew(content);
	if (list == NULL)
		print_red(" MALLOC ERROR ");
	else
	{
		test_val = (list->next == NULL && list->content == NULL);
		print_test_infos(cpt++, test_val, 1);
		free(list);
	}
	free(content);
}
