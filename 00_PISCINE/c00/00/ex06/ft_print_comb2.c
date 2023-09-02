/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:45:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/09 16:05:18 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2_printer(int nb)
{
	char	digit;

	digit = (char)(nb / 10) + '0';
	write(1, &digit, 1);
	digit = (char)(nb % 10) + '0';
	write(1, &digit, 1);
}

void	ft_print_comb2(void)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	while (nb1 <= 99)
	{
		nb2 = nb1 + 1;
		while (nb2 <= 99)
		{
			ft_print_comb2_printer(nb1);
			write(1, " ", 1);
			ft_print_comb2_printer(nb2);
			if (nb1 != 98 || nb2 != 99)
				write(1, ", ", 2);
			nb2++;
		}
		nb1++;
	}
}
