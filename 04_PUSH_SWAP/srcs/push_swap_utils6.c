/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:15:32 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/02 18:15:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_handle_printf_errors(t_ps_data *data, int returned)
{
	if (returned == -1)
	{
		data->clear(&data);
		exit(1);
	}
}

bool	push_swap_stack_a_to_array(t_ps_data *data)
{
	t_list	*list;
	int		*res;
	size_t	i;
	size_t	size;

	if (data == NULL || data->stack_a == NULL || (data->stack_a)->list == NULL)
		return (false);
	if (data->stack_a_array != NULL)
	{
		free(data->stack_a_array);
		data->stack_a_array = NULL;
	}
	list = (data->stack_a)->list;
	size = (data->stack_a)->size;
	res = (int *) malloc(size * sizeof(int));
	if (res == NULL)
		return (false);
	i = 0;
	while (i < size && list != NULL)
	{
		res[i++] = *((int *)(list->content));
		list = list->next;
	}
	data->stack_a_array = res;
	return (true);
}
