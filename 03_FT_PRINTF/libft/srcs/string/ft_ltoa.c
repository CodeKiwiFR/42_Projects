/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:20:15 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/12 17:55:47 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	extract_nb(char *res, long nb, size_t nb_len)
{
	long	div;
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

char	*ft_ltoa(long nb)
{
	char	*res;
	size_t	nb_len;

	if (nb == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	nb_len = ft_get_nb_len(nb);
	res = (char *) ft_calloc(nb_len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	extract_nb(res, nb, nb_len);
	return (res);
}
