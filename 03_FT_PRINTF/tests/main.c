/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:43:08 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/28 10:48:18 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//int	v1;
	//int	v2;

	//v1 = ft_printf("Bonjour je suis %d la\n");
	//v2 = printf("Bonjour je suis %www la\n");
	//printf("V1: %d - V2: %d\n", v1, v2);
	//return (0);

	ssize_t	ret;

	ret = ft_putendl_fd("hello", 1);
	printf("\nRET: %ld\n", ret);
	return (0);
}
