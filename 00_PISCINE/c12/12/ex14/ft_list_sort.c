/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:52:32 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/31 13:34:53 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size2(t_list *begin_list)
{
	int		count;
	t_list	*current;

	count = 0;
	current = begin_list;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_list	*ft_list_at2(t_list *begin_list, unsigned int nbr)
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

void	ft_swapper(void **elem1, void **elem2)
{
	void	*temp;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current_i;
	t_list	*current_j;
	int		size;
	int		i;
	int		j;

	size = ft_list_size2(*begin_list);
	i = 0;
	while (i < size)
	{
		current_i = ft_list_at2(*begin_list, i);
		j = i + 1;
		while (j < size)
		{
			current_j = ft_list_at2(*begin_list, j);
			if ((*cmp)(current_i->data, current_j->data) > 0)
				ft_swapper(&(current_i->data), &(current_j)->data);
			j++;
		}
		i++;
	}
}
