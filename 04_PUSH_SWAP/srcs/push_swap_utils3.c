/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/09 20:46:57 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_pa(t_ps_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*head;

	if (data == NULL || data->stack_a == NULL || data->stack_b == NULL)
		return ;
	stack_a = data->stack_a;
	stack_b = data->stack_b;
	head = stack_b->pop_link(stack_b);
	if (head == NULL)
		return ;
	stack_a->push_link(stack_a, head);
}

void	push_swap_pb(t_ps_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*head;

	if (data == NULL || data->stack_a == NULL || data->stack_b == NULL)
		return ;
	stack_a = data->stack_a;
	stack_b = data->stack_b;
	head = stack_a->pop_link(stack_a);
	if (head == NULL)
		return ;
	stack_b->push_link(stack_b, head);
}

void	push_swap_ra(t_ps_data *data)
{
	t_stack	*stack_a;

	if (data == NULL || data->stack_a == NULL)
		return ;
	stack_a = data->stack_a;
	stack_a->rotate(stack_a);
}

void	push_swap_rb(t_ps_data *data)
{
	t_stack	*stack_b;

	if (data == NULL || data->stack_b == NULL)
		return ;
	stack_b = data->stack_b;
	stack_b->rotate(stack_b);
}

void	push_swap_rr(t_ps_data *data)
{
	if (data == NULL)
		return ;
	data->ra(data);
	data->rb(data);
}
