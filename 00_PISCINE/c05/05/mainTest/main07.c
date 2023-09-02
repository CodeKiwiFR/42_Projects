/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main07.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:43:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/16 17:55:21 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_find_next_prime(int nb);

int	main(int argc, char **argv)
{
	int	nb;
	int	next_prime;

	if (argc > 1)
	{
		nb = atoi(argv[1]);
		next_prime = ft_find_next_prime(nb);
		printf("Next: %d\n", next_prime);
	}
	return (0);
}
