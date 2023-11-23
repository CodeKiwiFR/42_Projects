/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:09:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/21 11:01:34 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*nb;
	long	res;
	int		sign;

	if (nptr == NULL)
		return (0);
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
