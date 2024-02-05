/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:32:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 12:48:53 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_sort_size_three(t_ps_data *data, int v0, int v1, int v2)
{
	if (data == NULL || (v0 < v1 && v1 < v2))
		return ;
	else if (v0 < v2 && v2 < v1)
	{
		data->ra(data, true);
		data->sa(data, true);
		data->rra(data, true);
	}
	else if (v1 < v0 && v0 < v2)
		data->sa(data, true);
	else if (v2 < v0 && v0 < v1)
		data->rra(data, true);
	else if (v1 < v2 && v2 < v0)
		data->ra(data, true);
	else
	{
		data->ra(data, true);
		data->sa(data, true);
	}
}

void	sort_size_three(t_ps_data *data)
{
	int		v0;
	int		v1;
	int		v2;
	t_list	*stack_content;

	if (
		data == NULL || data->stack_a == NULL || (data->stack_a)->list == NULL
		|| (data->stack_a)->size != 3
		|| data->is_sorted_stack(data, STACK_A_LETTER)
	)
		return ;
	stack_content = (data->stack_a)->list;
	v0 = *((int *)(stack_content)->content);
	stack_content = stack_content->next;
	v1 = *((int *)(stack_content)->content);
	stack_content = stack_content->next;
	v2 = *((int *)(stack_content)->content);
	process_sort_size_three(data, v0, v1, v2);
}

size_t	min_size_t(size_t n1, size_t n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}
