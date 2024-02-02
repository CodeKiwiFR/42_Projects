/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/02 15:35:56 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_ps_data *data)
{
	size_t	i;

	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->is_sorted_stack(data, STACK_A_LETTER)
	)
		return ;
	if (!(data->stack_a_to_array(data)))
	{
		data->clear(&data);
		ft_dprintf(STDERR_FILENO, ERROR_MESSAGE);
		exit(1);
	}
	rev_sort_int_array(data->stack_a_array, (data->stack_a)->size);
	i = 0;
	while (i < (data->stack_a)->size)
	{
		ft_printf("nb: %d\n", (data->stack_a_array)[i]);
		i++;
	}
}
