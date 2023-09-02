/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:14:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/23 09:42:46 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_stock_str.h"

int	main(int argc, char **argv)
{
	t_stock_str	*array;

	array = ft_strs_to_tab(argc, argv);
	ft_show_tab(array);
	return (0);
}
