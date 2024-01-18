/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/18 18:18:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Adds nb to the stack_a of the given data
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
 *	Checks for duplicate integers inside of stack_a member of given data
 *	Returns true if a duplicate is found, else returns false
 */
bool	push_swap_found_duplicates_a(t_ps_data *data)
{
	t_list	*curr;
	t_list	*next;
	int		curr_nb;
	int		next_nb;

	if (data == NULL || data->stack_a == NULL || (data->stack_a)->list == NULL)
		return (false);
	curr = (data->stack_a)->list;
	while (curr->next != NULL && curr->content != NULL)
	{
		curr_nb = *((int *)(curr->content));
		next = curr->next;
		while (next != NULL)
		{
			if (next->content == NULL)
				return (false);
			next_nb = *((int *)(next->content));
			if (curr_nb == next_nb)
				return (true);
			next = next->next;
		}
		curr = curr->next;
	}
	return (false);
}

/*
 *	Checks if the stack 'a' or 'b' from data is sorted
 *	Returns true if it is, else returns false
 *	If the stack is empty, returns true
 *	If there is an error (NULL pointer or bad stack_letter), returns false
 */
bool	push_swap_is_sorted_stack(t_ps_data *data, char stack_letter)
{
	t_stack	*stack;
	t_list	*list;
	int		nb1;
	int		nb2;

	if (data == NULL || (stack_letter != 'a' && stack_letter != 'b'))
		return (false);
	if (stack_letter == 'a')
		stack = data->stack_a;
	else
		stack = data->stack_b;
	if (stack == NULL)
		return (false);
	list = stack->list;
	if (list == NULL)
		return (true);
	while (list->next != NULL)
	{
		nb1 = *((int *)list->content);
		nb2 = *((int *)(list->next)->content);
		if (nb1 > nb2)
			return (false);
		list = list->next;
	}
	return (true);
}

/*
 *	Checks if the stack 'a' or 'b' from data is reverse sorted
 *	Returns true if it is, else returns false
 *	If the stack is empty, returns true
 *	If there is an error (NULL pointer or bad stack_letter), returns false
 */
bool	push_swap_is_rev_sorted_stack(t_ps_data *data, char stack_letter)
{
	t_stack	*stack;
	t_list	*list;
	int		nb1;
	int		nb2;

	if (data == NULL || (stack_letter != 'a' && stack_letter != 'b'))
		return (false);
	if (stack_letter == 'a')
		stack = data->stack_a;
	else
		stack = data->stack_b;
	if (stack == NULL)
		return (false);
	list = stack->list;
	if (list == NULL)
		return (true);
	while (list->next != NULL)
	{
		nb1 = *((int *)list->content);
		nb2 = *((int *)(list->next)->content);
		if (nb1 < nb2)
			return (false);
		list = list->next;
	}
	return (true);
}
