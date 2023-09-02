/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:11:35 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/10 16:11:28 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	div;
	int	mod;

	div = 3 / 2;
	mod = 3 % 2;
	printf("Before: div = %d - mod = %d\n", div, mod);
	ft_div_mod(107, 11, &div, &mod);
	printf("After: div = %d - mod = %d\n", div, mod);
	return (0);
}
