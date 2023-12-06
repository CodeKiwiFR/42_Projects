/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:43:08 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/06 19:31:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//int		v1;
	//int		v2;
	const char	*format = "%wy %wyHello World %www!%\n";

	ft_printf(format, 50);
	//v1 = ft_printf(format, 50);
	//v2 = printf(format, 50);
	//printf("V1: %d - V2: %d - LEN: %zu\n", v1, v2, ft_strlen(format));
	return (0);
}
