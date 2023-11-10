/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:26 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 12:00:28 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nb_size(long nb)
{
	size_t	size;

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

static void	extract_nb(char *res, long nb, size_t nb_len)
{
	int		div;
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		nb_len--;
		nb *= -1;
		res[i] = '-';
		i++;
	}
	div = 1;
	while (--nb_len > 0)
		div *= 10;
	while (div > 0)
	{
		res[i] = nb / div + '0';
		nb %= div;
		div /= 10;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	size_t	nb_len;

	nb = (long) n;
	nb_len = get_nb_size(nb);
	res = (char *) ft_calloc(nb_len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	extract_nb(res, nb, nb_len);
	return (res);
}
