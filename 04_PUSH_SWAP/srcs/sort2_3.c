/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 14:45:16 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort2_rot_a_and_b(t_ps_data *data, t_cost *min_cost)
{
	size_t	ra;
	size_t	rb;
	size_t	rr;

	ra = min_cost->idx_a;
	rb = min_cost->idx_b;
	rr = min_size_t(ra, rb);
	ra -= rr;
	rb -= rr;
	while (rr > 0)
	{
		data->rr(data, true);
		rr--;
	}
	while (ra > 0)
	{
		data->ra(data, true);
		ra--;
	}
	while (rb > 0)
	{
		data->rb(data, true);
		rb--;
	}
}

static void	sort2_rot_a_rrot_b(t_ps_data *data, t_cost *min_cost)
{
	size_t	ra;
	size_t	rrb;

	ra = min_cost->idx_a;
	rrb = (data->stack_b)->size - (min_cost->idx_b);
	while (ra > 0)
	{
		data->ra(data, true);
		ra--;
	}
	while (rrb > 0)
	{
		data->rrb(data, true);
		rrb--;
	}
}

static void	sort2_rrot_a_rot_b(t_ps_data *data, t_cost *min_cost)
{
	size_t	rra;
	size_t	rb;

	rra = (data->stack_a)->size - (min_cost->idx_a);
	rb = min_cost->idx_b;
	while (rra > 0)
	{
		data->rra(data, true);
		rra--;
	}
	while (rb > 0)
	{
		data->rb(data, true);
		rb--;
	}
}

static void	sort2_rrot_a_and_b(t_ps_data *data, t_cost *min_cost)
{
	size_t	rra;
	size_t	rrb;
	size_t	rrr;

	rra = (data->stack_a)->size - (min_cost->idx_a);
	rrb = (data->stack_b)->size - (min_cost->idx_b);
	rrr = min_size_t(rra, rrb);
	rra -= rrr;
	rrb -= rrr;
	while (rrr > 0)
	{
		data->rrr(data, true);
		rrr--;
	}
	while (rra > 0)
	{
		data->rra(data, true);
		rra--;
	}
	while (rrb > 0)
	{
		data->rrb(data, true);
		rrb--;
	}
}

void	sort2_a_to_b_move(t_ps_data *data, t_cost *min_cost)
{
	if (
		data == NULL || min_cost == NULL
		|| min_cost->type == COST_TYPE_UNDEFINED
	)
		return ;
	if (min_cost->type == COST_TYPE_ROT_A_AND_B)
		sort2_rot_a_and_b(data, min_cost);
	else if (min_cost->type == COST_TYPE_ROT_A_RROT_B)
		sort2_rot_a_rrot_b(data, min_cost);
	else if (min_cost->type == COST_TYPE_RROT_A_ROT_B)
		sort2_rrot_a_rot_b(data, min_cost);
	else if (min_cost->type == COST_TYPE_RROT_A_AND_B)
		sort2_rrot_a_and_b(data, min_cost);
}
