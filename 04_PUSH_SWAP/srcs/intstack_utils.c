/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intstack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:53:56 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 10:56:56 by mhotting         ###   ########.fr       */
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

int	get_value_at_index(t_ps_data *data, char letter, size_t index)
{
	t_list	*list;
	size_t	curr_index;
	int		curr_value;

	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| (data->stack_a)->list == NULL || (data->stack_b)->list == NULL
		|| (letter != STACK_A_LETTER && letter != STACK_B_LETTER)
	)
		return (0);
	if (letter == STACK_A_LETTER)
		list = (data->stack_a)->list;
	else
		list = (data->stack_b)->list;
	curr_index = 0;
	while (curr_index < index && list != NULL)
	{
		curr_value = *((int *)(list->content));
		list = list->next;
		curr_index++;
	}
	if (list == NULL)
		return (0);
	return (*((int *)(list->content)));
}
