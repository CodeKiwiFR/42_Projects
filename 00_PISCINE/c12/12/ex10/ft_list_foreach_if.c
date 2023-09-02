/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:14:09 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/31 00:17:16 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(
		t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)()
		)
{
	t_list	*current;

	current = begin_list;
	while (current != NULL)
	{
		if ((*cmp)(current->data, data_ref) == 0)
			(*f)(current->data);
		current = current->next;
	}
}
