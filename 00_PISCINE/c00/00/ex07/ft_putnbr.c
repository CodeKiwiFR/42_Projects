/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:12:10 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/09 18:26:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nb_size;
	long	reminder;

	reminder = nb;
	if (reminder < 0)
	{
		write(1, "-", 1);
		reminder *= -1;
	}
	nb_size = 10;
	while (reminder / nb_size != 0)
		nb_size *= 10;
	while (nb_size != 1)
	{
		nb_size /= 10;
		ft_putchar((char)(reminder / nb_size) + '0');
		reminder %= nb_size;
	}
	return ;
}
