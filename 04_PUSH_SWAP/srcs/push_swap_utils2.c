/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/11 18:10:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Adds nb to the stack_A of the given data
 *	Allocates a pointer to an int in order to store an allocated int
 *	Returns true on success, false on failure
 */
bool	push_swap_push_a(t_ps_data *data, int nb)
{
	t_stack	*stack_a;
	int		*nb_allocated;

	if (data == NULL || data->stack_a == NULL)
		return (false);
	nb_allocated = (int *) malloc(sizeof(int));
	if (nb_allocated == NULL)
		return (false);
	*nb_allocated = nb;
	stack_a = data->stack_a;
	if (!(stack_a->push_data(stack_a, (void *) nb_allocated)))
	{
		free(nb_allocated);
		return (false);
	}
	return (true);
}

/*
 *	Reverses the content of stack_a of the given data
 */
void	push_swap_reverse_a(t_ps_data *data)
{
	if (data == NULL || data->stack_a == NULL)
		return ;
	(data->stack_a)->reverse(data->stack_a);
}

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
