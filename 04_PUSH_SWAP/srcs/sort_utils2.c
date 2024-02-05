/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:32:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 09:23:07 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multiple_ra(t_ps_data *data, size_t nb)
{
	size_t	i;

	if (
		data == NULL || data->stack_a == NULL
		|| (data->stack_a)->size < 2
	)
		return ;
	i = 0;
	while (i < nb)
	{
		data->ra(data, true);
		i++;
	}
}

void	multiple_rra(t_ps_data *data, size_t nb)
{
	size_t	i;

	if (
		data == NULL || data->stack_a == NULL
		|| (data->stack_a)->size < 2
	)
		return ;
	i = 0;
	while (i < nb)
	{
		data->rra(data, true);
		i++;
	}
}

void	multiple_rb(t_ps_data *data, size_t nb)
{
	size_t	i;

	if (
		data == NULL || data->stack_b == NULL
		|| (data->stack_b)->size < 2
	)
		return ;
	i = 0;
	while (i < nb)
	{
		data->rb(data, true);
		i++;
	}
}

void	multiple_rrb(t_ps_data *data, size_t nb)
{
	size_t	i;

	if (
		data == NULL || data->stack_b == NULL
		|| (data->stack_b)->size < 2
	)
		return ;
	i = 0;
	while (i < nb)
	{
		data->rrb(data, true);
		i++;
	}
}
