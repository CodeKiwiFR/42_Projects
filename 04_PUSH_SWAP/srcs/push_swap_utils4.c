/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/29 23:44:45 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Pushes the top element of stack_b on stack_a for given data
 */
void	push_swap_pa(t_ps_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*head;
	int		returned;

	if (data == NULL || data->stack_a == NULL || data->stack_b == NULL)
		return ;
	stack_a = data->stack_a;
	stack_b = data->stack_b;
	head = stack_b->pop_link(stack_b);
	if (head == NULL)
		return ;
	stack_a->push_link(stack_a, head);
	returned = ft_printf("pa\n");
	return (data->handle_printf_error(data, returned));
}

/*
 *	Pushes the top element of stack_a on stack_b for given data
 */
void	push_swap_pb(t_ps_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*head;
	int		returned;

	if (data == NULL || data->stack_a == NULL || data->stack_b == NULL)
		return ;
	stack_a = data->stack_a;
	stack_b = data->stack_b;
	head = stack_a->pop_link(stack_a);
	if (head == NULL)
		return ;
	stack_b->push_link(stack_b, head);
	returned = ft_printf("pb\n");
	return (data->handle_printf_error(data, returned));
}

/*
 *	Rotates stack_a of given data
 *	The head is put at the end of stack_a and other elements are moved up
 */
void	push_swap_ra(t_ps_data *data)
{
	t_stack	*stack_a;
	int		returned;

	if (data == NULL || data->stack_a == NULL || (data->stack_a)->size < 2)
		return ;
	stack_a = data->stack_a;
	stack_a->rotate(stack_a);
	returned = ft_printf("ra\n");
	return (data->handle_printf_error(data, returned));
}

/*
 *	Rotates stack_b of given data
 *	The head is put at the end of stack_a and other elements are moved up
 */
void	push_swap_rb(t_ps_data *data)
{
	t_stack	*stack_b;
	int		returned;

	if (data == NULL || data->stack_b == NULL || (data->stack_b)->size < 2)
		return ;
	stack_b = data->stack_b;
	stack_b->rotate(stack_b);
	returned = ft_printf("rb\n");
	return (data->handle_printf_error(data, returned));
}

/*
 *	Rotates stack_a and stack_b of given data
 *	The head is put at the end of both stacks and other elements are moved up
 */
void	push_swap_rr(t_ps_data *data)
{
	bool	ra;
	bool	rb;
	int		returned;

	ra = false;
	if (data != NULL && data->stack_a != NULL && (data->stack_a)->size >= 2)
	{
		(data->stack_a)->rotate(data->stack_a);
		ra = true;
	}
	rb = false;
	if (data != NULL && data->stack_b != NULL && (data->stack_b)->size >= 2)
	{
		(data->stack_b)->rotate(data->stack_b);
		rb = true;
	}
	if (ra && rb)
		returned = ft_printf("rr\n");
	else if (ra)
		returned = ft_printf("ra\n");
	else if (rb)
		returned = ft_printf("rb\n");
	else
		returned = 0;
	return (data->handle_printf_error(data, returned));
}
