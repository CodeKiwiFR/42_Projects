/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:29:10 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/31 16:40:19 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size6(t_list *begin_list)
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

t_list	*ft_list_at6(t_list *begin_list, unsigned int nbr)
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

void	ft_swapper6(void **elem1, void **elem2)
{
	void	*temp;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void	ft_list_sort6(t_list **begin_list, int (*cmp)())
{
	t_list	*current_i;
	t_list	*current_j;
	int		size;
	int		i;
	int		j;

	size = ft_list_size6(*begin_list);
	i = 0;
	while (i < size)
	{
		current_i = ft_list_at6(*begin_list, i);
		j = i + 1;
		while (j < size)
		{
			current_j = ft_list_at6(*begin_list, j);
			if ((*cmp)(current_i->data, current_j->data) > 0)
				ft_swapper6(&(current_i->data), &(current_j)->data);
			j++;
		}
		i++;
	}
}

void	ft_sorted_list_merge(
		t_list **begin_list1, t_list *begin_list2, int (*cmp)()
)
{
	t_list	*current;

	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	current = *begin_list1;
	while (current->next != NULL)
		current = current->next;
	current->next = begin_list2;
	ft_list_sort6(begin_list1, cmp);
}
