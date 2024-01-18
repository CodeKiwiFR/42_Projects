/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/18 19:32:05 by mhotting         ###   ########.fr       */
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

	if (data == NULL || data->stack_a == NULL || (data->stack_a)->size < 2)
		return ;
	stack_a = data->stack_a;
	stack_a->rev_rotate(stack_a);
	ft_printf("rra\n");
}

/*
 *	Reverse rotates stack_b of given data
 *	The tail is put at the top of stack_b and other elements are moved down
 */
void	push_swap_rrb(t_ps_data *data)
{
	t_stack	*stack_b;

	if (data == NULL || data->stack_b == NULL || (data->stack_b)->size < 2)
		return ;
	stack_b = data->stack_b;
	stack_b->rev_rotate(stack_b);
	ft_printf("rrb\n");
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

	if (data == NULL)
		return ;
	rra = false;
	if (data->stack_a != NULL && (data->stack_a)->size >= 2)
	{
		(data->stack_a)->rev_rotate(data->stack_a);
		rra = true;
	}
	rrb = false;
	if (data->stack_b != NULL && (data->stack_b)->size >= 2)
	{
		(data->stack_b)->rev_rotate(data->stack_b);
		rrb = true;
	}
	if (rra && rrb)
		ft_printf("rrr\n");
	else if (rra)
		ft_printf("rra\n");
	else if (rrb)
		ft_printf("rrb\n");
}
