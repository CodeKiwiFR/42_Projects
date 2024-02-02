/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:49:03 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/02 15:26:02 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_sort(t_ps_data *data)
{
	size_t	stack_size;

	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->is_sorted_stack(data, STACK_A_LETTER)
	)
		return ;
	stack_size = (data->stack_a)->size;
	if (stack_size < 2)
		return ;
	else if (stack_size == 2)
		data->sa(data, true);
	else if (stack_size == 3)
		sort_size_three(data);
	else if (stack_size <= 5)
		sort1(data);
	else
		sort2(data);
}

int	main(int argc, char **argv)
{
	t_ps_data	*data;
	bool		returned;

	if (argc == 1)
		return (0);
	data = ps_data_init();
	if (data == NULL)
		return (0);
	if (argc == 2)
		returned = parse_one_arg(data, argv[1]);
	else
		returned = parse_args(data, argc - 1, argv + 1);
	if (!returned || data->found_dup_a(data))
	{
		data->clear(&data);
		ft_dprintf(STDERR_FILENO, ERROR_MESSAGE);
		return (1);
	}
	if (!(data->is_sorted_stack(data, STACK_A_LETTER)))
		process_sort(data);
	data->clear(&data);
	return (0);
}
