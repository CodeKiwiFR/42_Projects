/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:45:45 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 14:49:04 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int	i;
	int	res;

	if (argc < 2)
	{
		res = 0;
		res = ft_read_and_print_file(0);
		if (res == -1)
		{
			ft_putstr(strerror(errno), 2);
			ft_putchar('\n', 2);
		}
		return (0);
	}
	i = ft_check_flags(argc - 1, argv + 1);
	if (i == -1)
		return (0);
	ft_read_all_files(argc - 1, argv + 1);
	return (0);
}
