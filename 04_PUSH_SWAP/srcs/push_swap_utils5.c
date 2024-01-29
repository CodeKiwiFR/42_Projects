/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/29 23:38:35 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Reverse rotates stack_a of given data
 *	The tail is put at the top of stack_a and other elements are moved down
 */

void	push_swap_rra(t_ps_data *data)
{
	t_stack	*stack_a;
	int		returned;

	if (data == NULL || data->stack_a == NULL || (data->stack_a)->size < 2)
		return ;
	stack_a = data->stack_a;
	stack_a->rev_rotate(stack_a);
	returned = ft_printf("rra\n");
	return (data->handle_printf_error(data, returned));
}

/*
 *	Reverse rotates stack_b of given data
 *	The tail is put at the top of stack_b and other elements are moved down
 */
void	push_swap_rrb(t_ps_data *data)
{
	t_stack	*stack_b;
	int		returned;

	if (data == NULL || data->stack_b == NULL || (data->stack_b)->size < 2)
		return ;
	stack_b = data->stack_b;
	stack_b->rev_rotate(stack_b);
	returned = ft_printf("rrb\n");
	return (data->handle_printf_error(data, returned));
}

/*
 *	Reverse rotates stack_a and stack_b of given data
 *	The tail is put at the top of both stack_a and stack_b
 *	Other elements are moved down
 */
void	push_swap_rrr(struct s_ps_data *data)
{
	bool	rra;
	bool	rrb;
	int		returned;

	rra = false;
	if (data != NULL && data->stack_a != NULL && (data->stack_a)->size >= 2)
	{
		(data->stack_a)->rev_rotate(data->stack_a);
		rra = true;
	}
	rrb = false;
	if (data != NULL && data->stack_b != NULL && (data->stack_b)->size >= 2)
	{
		(data->stack_b)->rev_rotate(data->stack_b);
		rrb = true;
	}
	if (rra && rrb)
		returned = ft_printf("rrr\n");
	else if (rra)
		returned = ft_printf("rra\n");
	else if (rrb)
		returned = ft_printf("rrb\n");
	else
		returned = 0;
	return (data->handle_printf_error(data, returned));
}
