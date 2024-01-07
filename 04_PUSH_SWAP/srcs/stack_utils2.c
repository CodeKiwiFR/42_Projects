/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:04:50 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/07 17:32:46 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
 *	Clears the given stack by freeing the list and its content
 *	Clears the stack given as input and set the given pointer to NULL
 *	NB:	- del parameter can be NULL, then the list is freed but the contents
 *		are not freed (useful if list content has not been allocated
 */
void	stack_clear(t_stack **stack, void (*del)(void *))
{
	if (stack == NULL || *stack == NULL)
		return ;
	ft_lstclear(&((*stack)->list), del);
	free(*stack);
	*stack = NULL;
}
