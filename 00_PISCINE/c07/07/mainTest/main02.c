/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:09:20 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/17 22:31:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_ultimate_range(int **range, int min, int max);

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
	int	returned_value;
	int	min;
	int	max;

	if (argc == 3)
	{
		min = atoi(argv[1]);
		max = atoi(argv[2]);
		size = max - min;
		returned_value = ft_ultimate_range(&tab, min, max);
		if (!tab)
		{
			printf("ERROR - Array was not created (returned %d - tab addr: %p)\n", returned_value, tab);
			return (0);
		}
		printf("Min: %d - Max: %d - Size: %d\n", min, max, size);
		ft_print_tab(tab, size);
		printf("Returned value: %d\n", returned_value);
		free(tab);
	}
	return (0);
}
