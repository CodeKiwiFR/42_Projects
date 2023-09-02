/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:43:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/16 10:52:07 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_iterative_factorial(int nb);

int	main(int argc, char **argv)
{
	int	nb;

	if (argc > 1)
	{
		nb = atoi(argv[1]);
		printf("%d! = %d\n", nb, ft_iterative_factorial(nb));
	}
	return (0);
}
