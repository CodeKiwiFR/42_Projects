/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:02 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 12:07:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_recursion(long nb, int fd)
{
	if (nb == 0)
		return ;
	ft_putnbr_fd_recursion(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long) n;
	if (nb == 0)
		return (ft_putchar_fd('0', fd));
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	ft_putnbr_fd_recursion(nb, fd);
}
