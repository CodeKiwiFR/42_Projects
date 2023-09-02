/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main07.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:11:35 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/11 09:13:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_print_table(int *tab, int size)
{
	int	index;

	index = 0;
	printf("[");
	while (index < size)
	{
		printf("%d", tab[index]);
		if (index < size - 1)
			printf(", ");
		index++;
	}
	printf("]\n");
}

int	main(void)
{
	int	tab[6] = {1, 2, 3, 4, 5, 6};
	int	size = 6;
	int	tab1[2] = {1, 2};
	int	size1 = 2;
	int	tab2[11] = {10, 12, 14, 17, 19, 21, 78, 89, 14, 15, 23};
	int	size2 = 11;
	int	tab3[] = {};
	int	size3 = 0;


	ft_print_table(tab, size);
	ft_rev_int_tab(tab, size);
	ft_print_table(tab, size);
	printf("\n");

	ft_print_table(tab1, size1);
	ft_rev_int_tab(tab1, size1);
	ft_print_table(tab1, size1);
	printf("\n");

	ft_print_table(tab2, size2);
	ft_rev_int_tab(tab2, size2);
	ft_print_table(tab2, size2);
	printf("\n");

	ft_print_table(tab3, size3);
	ft_rev_int_tab(tab3, size3);
	ft_print_table(tab3, size3);

	return (0);
}
