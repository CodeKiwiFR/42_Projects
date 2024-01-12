/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/12 09:23:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Swaps the first two elements of the stack_a
 */
void	push_swap_sa(t_ps_data *data)
{
	t_stack	*stack_a;

	if (data == NULL || data->stack_a == NULL)
		return ;
	stack_a = data->stack_a;
	stack_a->swap(stack_a);
}

/*
 *	Swaps the first two elements of the stack_b
 */
void	push_swap_sb(t_ps_data *data)
{
	t_stack	*stack_b;

	if (data == NULL || data->stack_b == NULL)
		return ;
	stack_b = data->stack_b;
	stack_b->swap(stack_b);
}

/*
 *	Swaps the first two elements of both stack_a and stack_b
 */
void	push_swap_ss(t_ps_data *data)
{
	if (data == NULL)
		return ;
	data->sa(data);
	data->sb(data);
}
