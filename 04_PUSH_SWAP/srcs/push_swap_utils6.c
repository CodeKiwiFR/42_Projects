/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/08 10:01:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Displays the content of a t_stack element
 */
static void	display_int_stack(t_stack *stack)
{
	t_list	*current;

	if (stack == NULL || stack->list == NULL)
	{
		ft_printf("Stack is empty...\n");
		return ;
	}
	current = stack->list;
	ft_printf("- content: ");
	while (current != NULL)
	{
		ft_printf("% 10ld", *((t_int_type *)(current->content)));
		current = current->next;
		if (current != NULL)
			ft_printf(" | ");
	}
	ft_printf("\n");
}

/*
 *	Displays the content of a t_ps_data element
 *	Handles the returned value as a printf returned value
 *	If (-1) is given, the program is left after having cleaned the memory
 *	Else nothing happens
 */
void	push_swap_display(t_ps_data *data)
{
	if (data == NULL)
	{
		ft_printf("ERROR - The given push_swap data is NULL\n");
		return ;
	}
	ft_printf("#####################\n");
	ft_printf("#  PUSH_SWAP DATA:  #\n");
	ft_printf("#####################\n\n");
	ft_printf("STACK_A:\n\t");
	display_int_stack(data->stack_a);
	ft_printf("STACK_B:\n\t");
	display_int_stack(data->stack_b);
	ft_printf("\n###################\n\n");
}
