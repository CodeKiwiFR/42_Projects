/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:43:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/15 16:18:28 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(int argc, char **argv)
{
	int	nb;
	char	*base;

	if (argc > 2)
	{
		nb = atoi(argv[1]);
		base = argv[2];
		ft_putnbr_base(nb, base);
	}
	return (0);
}
