/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:13:27 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 18:40:35 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>            
#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int));

void	ft_print_tab(int *tab, int length)
{
	int	i;

	i = 0;
	printf("[");
	while (i < length)
	{
		printf("%d", tab[i]);
		if (i < length - 1)
			printf(", ");
		i++;
	}
	printf("]\n");
}

int	ft_test(int nb)
{
	return (nb + 10);
}

int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5, 6};
	int	*tab2;

	ft_print_tab(tab, 6);
	tab2 = ft_map(tab, 6, &ft_test);
	if (tab2 != NULL)
		ft_print_tab(tab2, 6);
	return (0);
}
