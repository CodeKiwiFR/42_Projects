/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:59:00 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/22 18:02:28 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_abs.h"

int	main(int ac, char **av)
{
	int	nb;

	if (ac > 1)
	{
		nb = atoi(av[1]);
		printf("Number: %d\n", nb);
		printf("Abs   : %d\n", ABS(nb));
	}
	return (0);
}
