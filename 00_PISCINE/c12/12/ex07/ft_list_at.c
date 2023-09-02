/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:18:29 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/30 23:37:13 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*current;
	unsigned int	i;

	if (nbr == 0)
		return (begin_list);
	i = 0;
	current = begin_list;
	while (current != 0)
	{
		if (i == nbr)
			return (current);
		i++;
		current = current->next;
	}
	return (0);
}
