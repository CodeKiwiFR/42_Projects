/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/18 19:15:05 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Swaps the first two elements of the stack_a
 */
void	push_swap_sa(t_ps_data *data)
{
	t_stack	*stack_a;

	if (data == NULL || data->stack_a == NULL || (data->stack_a)->size < 2)
		return ;
	stack_a = data->stack_a;
	stack_a->swap(stack_a);
	ft_printf("sa\n");
}

/*
 *	Swaps the first two elements of the stack_b
 */
void	push_swap_sb(t_ps_data *data)
{
	t_stack	*stack_b;

	if (data == NULL || data->stack_b == NULL || (data->stack_b)->size < 2)
		return ;
	stack_b = data->stack_b;
	stack_b->swap(stack_b);
	ft_printf("sb\n");
}

/*
 *	Swaps the first two elements of both stack_a and stack_b
 */
void	push_swap_ss(t_ps_data *data)
{
	bool	sa;
	bool	sb;

	if (data == NULL)
		return ;
	sa = false;
	if (data->stack_a != NULL && (data->stack_a)->size >= 2)
	{
		(data->stack_a)->swap(data->stack_a);
		sa = true;
	}
	sb = false;
	if (data->stack_b != NULL && (data->stack_b)->size >= 2)
	{
		(data->stack_b)->swap(data->stack_b);
		sb = true;
	}
	if (sa && sb)
		ft_printf("ss\n");
	else if (sa)
		ft_printf("sa\n");
	else if (sb)
		ft_printf("sb\n");
}
