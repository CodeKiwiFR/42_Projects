/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:09:31 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/09 14:21:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb_display(char c1, char c2, char c3, int display_limiter)
{
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
	if (display_limiter == 1)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	while (c1 <= '9')
	{
		c2 = c1 + 1;
		while (c2 <= '9')
		{
			c3 = c2 + 1;
			while (c3 <= '9')
			{
				if (c1 == '7' && c2 == '8' && c3 == '9')
					ft_print_comb_display(c1, c2, c3, 0);
				else
					ft_print_comb_display(c1, c2, c3, 1);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
