/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:47:06 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 21:18:06 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		ft_putchar((char)nbr + '0');
		return ;
	}
	ft_putnbr((int)(nbr / 10));
	ft_putchar(((char)(nbr % 10)) + '0');
}

int	ft_isspace(char c)
{
	if (
		c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v'
	)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		sign;
	long	number;

	number = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		number *= 10;
		number += (long)(*str - '0');
		str++;
	}
	return (sign * number);
}
