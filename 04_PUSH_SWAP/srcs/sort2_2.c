/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 14:10:08 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	sort2_get_index_in_b(t_ps_data *data, size_t index_in_a)
{
	t_list	*list;
	size_t	idx_b;
	size_t	idx_max_b;
	int		val_b;
	int		val_a;

	if (data == NULL || data->stack_a == NULL || data->stack_b == NULL)
		return (0);
	val_a = get_value_at_index(data, 'a', index_in_a);
	idx_max_b = get_max_index(data->stack_b);
	idx_b = 0;
	list = (data->stack_b)->list;
	while (idx_b < idx_max_b)
	{
		list = list->next;
		idx_b++;
	}
	while (list != NULL)
	{
		val_b = *((int *)(list->content));
		if (val_a > val_b)
			return (idx_b);
		idx_b++;
		list = list->next;
	}
	idx_b = 0;
	list = (data->stack_b)->list;
	while (idx_b < idx_max_b)
	{
		val_b = *((int *)(list->content));
		if (val_a > val_b)
			return (idx_b);
		list = list->next;
		idx_b++;
	}
	return (idx_max_b);
}
