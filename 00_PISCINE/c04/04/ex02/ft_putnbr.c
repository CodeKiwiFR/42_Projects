/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:58:34 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/15 12:17:01 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long	ft_eval_size(long nb)
{
	long	size;

	size = 1;
	while (nb / 10 > 0)
	{
		size *= 10;
		nb /= 10;
	}
	return (size);
}

void	ft_putnbr(int nb)
{
	long	nb_l;
	long	nb_size;
	char	digit;

	nb_l = (long)nb;
	if (nb_l < 0)
	{
		ft_putchar('-');
		nb_l *= -1;
	}
	nb_size = ft_eval_size(nb_l);
	while (nb_size >= 1)
	{
		digit = (char)(nb_l / nb_size) + '0';
		ft_putchar(digit);
		nb_l = nb_l % nb_size;
		nb_size /= 10;
	}
}
