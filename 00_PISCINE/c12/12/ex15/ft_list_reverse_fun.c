/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:35:57 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/31 13:50:46 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size3(t_list *begin_list)
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

t_list	*ft_list_at3(t_list *begin_list, unsigned int nbr)
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

void	ft_swapper2(void **elem1, void **elem2)
{
	void	*temp;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		j;
	int		size;
	t_list	*current_i;
	t_list	*current_j;

	size = ft_list_size3(begin_list);
	i = 0;
	j = size - 1;
	while (i < j)
	{
		current_i = ft_list_at3(begin_list, i);
		current_j = ft_list_at3(begin_list, j);
		ft_swapper2(&(current_i->data), &(current_j->data));
		i++;
		j--;
	}
}
