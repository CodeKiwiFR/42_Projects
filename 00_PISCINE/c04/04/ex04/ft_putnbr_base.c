/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:47:28 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/15 18:45:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_base_valid(char c)
{
	if (c > ' ' && c <= '~' && c != '+' && c != '-')
		return (1);
	return (0);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (!ft_is_base_valid(base[i]))
			return (-1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (!ft_is_base_valid(base[j]) || base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

void	ft_disp_base(long nb, char *base, int base_len)
{
	if (nb < base_len)
		ft_putchar(base[nb]);
	else
	{
		ft_disp_base(nb / base_len, base, base_len);
		ft_putchar(base[nb % base_len]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	long	base_len;

	base_len = ft_check_base(base);
	if (base_len == -1)
		return ;
	nb = (long)nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	ft_disp_base(nb, base, base_len);
}
