/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/30 22:21:06 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*current;

	if (begin_list == NULL || begin_list->next == NULL)
		return (begin_list);
	current = begin_list;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
