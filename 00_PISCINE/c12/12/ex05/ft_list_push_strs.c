/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:36:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/30 22:50:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*current;
	int		i;

	list = NULL;
	if (size <= 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		current = ft_create_elem(strs[i]);
		if (!current)
			return (list);
		if (list == NULL)
			list = current;
		else
		{
			current->next = list;
			list = current;
		}
		i++;
	}
	return (list);
}
