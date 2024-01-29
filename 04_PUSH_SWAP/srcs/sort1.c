/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/29 17:08:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	all_mins_a_to_b(t_ps_data *data)
{
	t_stack	*a;
	size_t	min_index;

	a = data->stack_a;
	while (a->size > 1)
	{
		min_index = get_min_index(a);
		if (min_index < a->size / 2)
		{
			while (min_index > 0)
			{
				data->ra(data);
				min_index--;
			}
		}
		else
		{
			while (min_index < a->size)
			{
				data->rra(data);
				min_index++;
			}
		}
		data->pb(data);
	}
}

static void	all_b_to_a(t_ps_data *data)
{
	while ((data->stack_b)->size > 0)
		data->pa(data);
}

void	sort1(t_ps_data *data)
{
	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->is_sorted_stack(data, 'a')
	)
		return ;
	all_mins_a_to_b(data);
	all_b_to_a(data);
	return ;
}
