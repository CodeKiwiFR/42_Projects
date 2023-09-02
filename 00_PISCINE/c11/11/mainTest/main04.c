/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:13:27 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/25 09:17:55 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>            
#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int	ft_is_lower(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (-1);
	else if (nb1 == nb2)
		return (0);
	else
		return (1);
}

int	main(void)
{
	int	tab[] = {1, 10, 20, 30, 40};
	int	tab2[] = {100, 1, 95, 2, 30};
	int	tab3[] = {100, 99, 98, 97, 96};
	int	tab4[] = {100};
	int	tab5[] = {};

	printf("Tab  is sorted: %d\n", ft_is_sort(tab, 5, &ft_is_lower));
	printf("Tab2 is sorted: %d\n", ft_is_sort(tab2, 5, &ft_is_lower));
	printf("Tab3 is sorted: %d\n", ft_is_sort(tab3, 5, &ft_is_lower));
	printf("Tab4 is sorted: %d\n", ft_is_sort(tab4, 1, &ft_is_lower));
	printf("Tab5 is sorted: %d\n", ft_is_sort(tab5, 0, &ft_is_lower));
	return (0);
}
