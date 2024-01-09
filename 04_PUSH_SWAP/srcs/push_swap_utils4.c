/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/09 20:47:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_rra(t_ps_data *data)
{
	t_stack	*stack_a;

	if (data == NULL || data->stack_a == NULL)
		return ;
	stack_a = data->stack_a;
	stack_a->rev_rotate(stack_a);
}

void	push_swap_rrb(t_ps_data *data)
{
	t_stack	*stack_b;

	if (data == NULL || data->stack_b == NULL)
		return ;
	stack_b = data->stack_b;
	stack_b->rev_rotate(stack_b);
}

void	push_swap_rrr(struct s_ps_data *data)
{
	if (data == NULL)
		return ;
	data->rra(data);
	data->rrb(data);
}
