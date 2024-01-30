/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intstack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:53:56 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/30 16:27:53 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_min_index(t_stack *stack)
{
	int		min;
	int		current_value;
	size_t	min_index;
	size_t	current_index;
	t_list	*current;

	if (stack == NULL || stack->list == NULL)
		return (0);
	current = stack->list;
	min = *((int *) current->content);
	min_index = 0;
	current = current->next;
	current_index = 1;
	while (current != NULL)
	{
		current_value = *((int *) current->content);
		if (current_value < min)
		{
			min = current_value;
			min_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (min_index);
}

size_t	get_max_index(t_stack *stack)
{
	int		max;
	int		current_value;
	size_t	max_index;
	size_t	current_index;
	t_list	*current;

	if (stack == NULL || stack->list == NULL)
		return (0);
	current = stack->list;
	max = *((int *) current->content);
	max_index = 0;
	current = current->next;
	current_index = 1;
	while (current != NULL)
	{
		current_value = *((int *) current->content);
		if (current_value > max)
		{
			max = current_value;
			max_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (max_index);
}
