/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:43:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/16 11:34:40 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_fibonacci(int index);

int	main(int argc, char **argv)
{
	int	index;

	if (argc > 1)
	{
		index = atoi(argv[1]);
		printf("fibo(%d) = %d\n", index, ft_fibonacci(index));
	}
	return (0);
}
