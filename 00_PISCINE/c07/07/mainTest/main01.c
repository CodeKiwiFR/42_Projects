/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:09:20 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/17 22:06:32 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	*ft_range(int min, int max);

void	ft_print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	printf("[");
	while (i < size)
	{
		printf("%d", tab[i]);
		if (i < size - 1)
			printf(", ");
		i++;
	}
	printf("]\n");
}

int	main(int argc, char **argv)
{
	int	*tab;
	int	size;
	int	min;
	int	max;

	if (argc == 3)
	{
		min = atoi(argv[1]);
		max = atoi(argv[2]);
		size = max - min;
		tab = ft_range(min, max);
		if (!tab)
		{
			printf("ERROR - Array was not created\n");
			return (0);
		}
		printf("Min: %d - Max: %d - Size: %d\n", min, max, size);
		ft_print_tab(tab, size);
		free(tab);
	}
	return (0);
}
