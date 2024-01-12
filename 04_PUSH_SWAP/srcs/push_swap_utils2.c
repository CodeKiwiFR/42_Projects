/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/12 09:46:42 by mhotting         ###   ########.fr       */
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
