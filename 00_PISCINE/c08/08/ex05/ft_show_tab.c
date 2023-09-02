/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:23:50 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/23 11:43:55 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr_pos(int nb)
{
	if (nb < 10)
	{
		ft_putchar((char)nb + '0');
		return ;
	}
	ft_putnbr_pos(nb / 10);
	ft_putchar(((char)(nb % 10)) + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	if (!par)
		return ;
	i = 0;
	while (par[i].str != 0)
	{
		if (par[i].str)
		{
			ft_putstr(par[i].str);
			ft_putchar('\n');
		}
		ft_putnbr_pos(par[i].size);
		ft_putchar('\n');
		if (par[i].copy)
		{
			ft_putstr(par[i].copy);
			ft_putchar('\n');
		}
		i++;
	}
}
