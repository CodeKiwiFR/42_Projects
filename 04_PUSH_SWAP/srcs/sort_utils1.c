/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:32:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/08 10:24:29 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Sorts the given data where stack A has a size of 3
 *	v0, v1, and v3 are the numbers contained in stack A
 */
static void	process_sort_size_three(
	t_ps_data *data, t_int_type v0, t_int_type v1, t_int_type v2
)
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

/*
 *	Sorts stack A of given data when this stack has a size of 3
 */
void	sort_size_three(t_ps_data *data)
{
	t_int_type	v0;
	t_int_type	v1;
	t_int_type	v2;
	t_list		*stack_content;

	if (
		data == NULL || data->stack_a == NULL || (data->stack_a)->list == NULL
		|| (data->stack_a)->size != 3
		|| ((data->stack_a)->list)->content == NULL
		|| data->is_sorted_stack(data, STACK_A_LETTER)
	)
		return ;
	stack_content = (data->stack_a)->list;
	v0 = *((t_int_type *)(stack_content)->content);
	stack_content = stack_content->next;
	v1 = *((t_int_type *)(stack_content)->content);
	stack_content = stack_content->next;
	v2 = *((t_int_type *)(stack_content)->content);
	process_sort_size_three(data, v0, v1, v2);
}

/*
 *	Returns the minimum between two size_t numbers
 */
size_t	min_size_t(size_t n1, size_t n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}
