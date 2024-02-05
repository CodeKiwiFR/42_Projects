/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 14:49:55 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort2_rotb(t_ps_data *data)
{
	size_t	max_index;
	size_t	size_b;

	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->is_rev_sorted_stack(data, STACK_B_LETTER)
		|| (data->stack_b)->size < 2
	)
		return ;
	max_index = get_max_index(data->stack_b);
	size_b = (data->stack_b)->size;
	if (max_index <= size_b / 2)
		multiple_rb(data, max_index);
	else
		multiple_rrb(data, (size_b - max_index));
}

static void	sort2_a_to_b(t_ps_data *data)
{
	t_cost	min_cost;

	if (data == NULL || data->stack_a == NULL || data->stack_b == NULL)
		return ;
	while ((data->stack_a)->size > 0)
	{
		sort2_calc_min_cost(data, &min_cost);
		sort2_a_to_b_move(data, &min_cost);
		data->pb(data, true);
	}
}

static void	sort2_init(t_ps_data *data)
{
	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->is_sorted_stack(data, STACK_A_LETTER)
		|| (data->stack_a)->size < 2
	)
		return ;
	data->pb(data, true);
	data->pb(data, true);
	if (!(data->is_rev_sorted_stack(data, STACK_B_LETTER)))
		data->sb(data, true);
}

void	sort2(t_ps_data *data)
{
	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->is_sorted_stack(data, STACK_A_LETTER)
		|| (data->stack_a)->size < 2
	)
		return ;
	sort2_init(data);
	sort2_a_to_b(data);
	sort2_rotb(data);
	while ((data->stack_b)->size > 0)
		data->pa(data, true);
	//data->display(data);
}
