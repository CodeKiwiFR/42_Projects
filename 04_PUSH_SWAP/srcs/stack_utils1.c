/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:04:50 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/07 17:00:50 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->list = NULL;
	stack->push = stack_push;
	stack->pop = stack_pop;
	stack->rotate = stack_rotate;
	stack->rev_rotate = stack_rev_rotate;
	stack->clear = stack_clear;
	return (stack);
}

bool	stack_push(t_stack *stack, void *data)
{
	t_list	*new;

	if (stack == NULL || data == NULL)
		return (false);
	new = ft_lstnew(data);
	if (new == NULL)
		return (false);
	new->next = stack->list;
	stack->list = new;
	return (true);
}

void	*stack_pop(t_stack *stack)
{
	t_list	*head;
	void	*data;

	if (stack == NULL || stack->list == NULL)
		return (NULL);
	head = stack->list;
	data = head->content;
	stack->list = head->next;
	free(head);
	return (data);
}

void	stack_rotate(t_stack *stack)
{
	t_list	*current;
	t_list	*head;

	if (stack == NULL || stack->list == NULL || (stack->list)->next == NULL)
		return ;
	head = stack->list;
	current = head->next;
	head->next = NULL;
	stack->list = current;
	while (current->next != NULL)
		current = current->next;
	current->next = head;
	return ;
}

void	stack_rev_rotate(t_stack *stack)
{
	t_list	*current;
	t_list	*prev;

	if (stack == NULL || stack->list == NULL || (stack->list)->next == NULL)
		return ;
	prev = NULL;
	current = stack->list;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack->list;
	stack->list = current;
}
