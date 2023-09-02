/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:50:11 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/31 12:15:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(
		t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *)
)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		if (current != NULL)
			next = current->next;
		if ((*cmp)(current->data, data_ref) == 0)
		{
			if (current == *begin_list)
				*begin_list = next;
			(*free_fct)(current->data);
			free(current);
			current = NULL;
			if (prev != NULL)
				prev->next = next;
		}
		prev = current;
		current = next;
	}
}
