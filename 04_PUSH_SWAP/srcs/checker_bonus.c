/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:28:48 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/29 20:26:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_data	*data;
	bool		returned;

	data = ps_data_init();
	if (argc == 1 || data == NULL)
		return (0);
	if (argc == 2)
		returned = parse_one_arg(data, argv[1]);
	else
		returned = parse_args(data, argc - 1, argv + 1);
	if (!returned || data->found_dup_a(data))
	{
		data->clear(&data);
		ft_printf("Error\n");
		return (1);
	}
	data->clear(&data);
	return (0);
}
