/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:23:01 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/30 22:12:07 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_link;

	new_link = ft_create_elem(data);
	if (!new_link)
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = new_link;
		new_link->next = NULL;
	}
	else
	{
		new_link->next = *begin_list;
		*begin_list = new_link;
	}
}
