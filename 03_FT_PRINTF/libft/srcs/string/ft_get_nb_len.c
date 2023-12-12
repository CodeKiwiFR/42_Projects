/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:23:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/12 17:45:29 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_nb_len(long nb)
{
	size_t	size;

	if (nb == LONG_MIN)
		return (20);
	size = 1;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb / 10 > 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}
