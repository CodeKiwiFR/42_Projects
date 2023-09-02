/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:43:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/15 12:21:34 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void	ft_putnbr(int nb);

int	main(int argc, char **argv)
{
	int	nb;

	if (argc > 1)
	{
		nb = atoi(argv[1]);
		ft_putnbr(nb);
	}
	else
	{
		ft_putnbr(0);
		write(1, "\n", 1);
		ft_putnbr(42);
		write(1, "\n", 1);
		ft_putnbr(INT_MIN);
		write(1, "\n", 1);
		ft_putnbr(INT_MAX);
		write(1, "\n", 1);
	}
	return (0);
}
