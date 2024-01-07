/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:49:03 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/07 17:34:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_stack *stack)
{
	t_list	*current;

	if (stack == NULL || stack->list == NULL)
	{
		ft_printf("Stack is empty...\n");
		return ;
	}
	current = stack->list;
	ft_printf("STACK: ");
	while (current != NULL)
	{
		ft_printf("%+3d", *((int *)(current->content)));
		current = current->next;
		if (current != NULL)
			ft_printf(" | ");
	}
	ft_printf("\n");
}

int	main(void)
{
	ft_printf("Hello from PUSH_SWAP()\n");
	return (0);
}
