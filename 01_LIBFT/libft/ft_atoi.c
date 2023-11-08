/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:09:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 17:14:59 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (
		c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v'
	)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char	*nb;
	long	res;
	int		sign;

	nb = (char *) nptr;
	res = 0;
	while (ft_isspace(*nb))
		nb++;
	sign = 1;
	if (*nb == '+')
		nb++;
	else if (*nb == '-')
	{
		nb++;
		sign *= -1;
	}
	while (ft_isdigit(*nb))
	{
		res = res * 10 + ((long)(*nb - '0'));
		nb++;
	}
	return ((int)(sign * res));
}
