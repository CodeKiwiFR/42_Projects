/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:11:35 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/10 15:55:53 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 42;
	printf("Before: a = %d , b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("After: a = %d , b = %d\n", a, b);
	return (0);
}
