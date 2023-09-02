/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:43:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 09:44:35 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

void	ft_print_hex(char c)
{
	char			*hex;
	unsigned char	u_c;

	u_c = (unsigned char) c;
	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[u_c / 16]);
	ft_putchar(hex[u_c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (ft_is_printable(*str))
			ft_putchar(*str);
		else
			ft_print_hex(*str);
		str++;
	}
}
