/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:43:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/16 11:12:22 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_iterative_power(int nb, int power);

int	main(int argc, char **argv)
{
	int	nb;
	int	pow;

	if (argc > 2)
	{
		nb = atoi(argv[1]);
		pow = atoi(argv[2]);
		printf("%d ** %d = %d\n", nb, pow, ft_iterative_power(nb, pow));
	}
	return (0);
}
