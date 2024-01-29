/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/29 23:34:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Swaps the first two elements of the stack_a
 */
void	push_swap_sa(t_ps_data *data)
{
	t_stack	*stack_a;
	int		returned;

	if (data == NULL || data->stack_a == NULL || (data->stack_a)->size < 2)
		return ;
	stack_a = data->stack_a;
	stack_a->swap(stack_a);
	returned = ft_printf("sa\n");
	return (data->handle_printf_error(data, returned));
}

/*
 *	Swaps the first two elements of the stack_b
 */
void	push_swap_sb(t_ps_data *data)
{
	t_stack	*stack_b;
	int		returned;

	if (data == NULL || data->stack_b == NULL || (data->stack_b)->size < 2)
		return ;
	stack_b = data->stack_b;
	stack_b->swap(stack_b);
	returned = ft_printf("sb\n");
	return (data->handle_printf_error(data, returned));
}

/*
 *	Swaps the first two elements of both stack_a and stack_b
 */
void	push_swap_ss(t_ps_data *data)
{
	bool	sa;
	bool	sb;
	int		returned;

	sa = false;
	if (data != NULL && data->stack_a != NULL && (data->stack_a)->size >= 2)
	{
		(data->stack_a)->swap(data->stack_a);
		sa = true;
	}
	sb = false;
	if (data != NULL && data->stack_b != NULL && (data->stack_b)->size >= 2)
	{
		(data->stack_b)->swap(data->stack_b);
		sb = true;
	}
	if (sa && sb)
		returned = ft_printf("ss\n");
	else if (sa)
		returned = ft_printf("sa\n");
	else if (sb)
		returned = ft_printf("sb\n");
	else
		returned = 0;
	return (data->handle_printf_error(data, returned));
}
