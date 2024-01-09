/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:49:03 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/09 22:04:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_data	*data;

	data = ps_data_init();
	if (argc == 1 || data == NULL)
		return (0);
	if (!parse_args(data, argc, argv))
	{
		data->clear(&data);
		ft_printf("Error\n");
		return (1);
	}
	data->display(data);
	data->clear(&data);
	return (0);
}
