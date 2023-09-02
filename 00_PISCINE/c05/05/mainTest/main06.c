/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main06.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:43:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/16 16:09:15 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_is_prime(int nb);

int	main(int argc, char **argv)
{
	int	nb;

	if (argc > 1)
	{
		nb = atoi(argv[1]);
		if (ft_is_prime(nb))
			printf("%d is PRIME\n", nb);
		else
			printf("%d is NOT PRIME\n", nb);
	}
	return (0);
}
