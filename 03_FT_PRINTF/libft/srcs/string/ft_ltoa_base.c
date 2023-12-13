/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:17:16 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/13 20:54:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_valid_base(char *base)
{
	size_t	i;
	size_t	j;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (false);
	i = 0;
	while (i < base_len)
	{
		if (!ft_isprint(base[i]))
			return (false);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static void	extract_number_base(char *res, size_t len_res, long nb, char *base)
{
	unsigned long	num;
	size_t			i;
	size_t			len_base;

	if (nb < 0)
		num = (unsigned long) -1 * nb;
	else
		num = (unsigned long) nb;
	len_base = ft_strlen(base);
	i = len_res - 1;
	while (num > 0)
	{
		res[i] = base[num % len_base];
		i--;
		num /= len_base;
	}
	if (nb < 0)
		res[0] = '-';
}

char	*ft_ltoa_base(long nb, char *base)
{
	char	*res;
	size_t	len_base;
	size_t	len_res;

	if (base == NULL || !is_valid_base(base))
		return (NULL);
	if (nb == 0)
		return (ft_ctoa(base[0]));
	len_base = ft_strlen(base);
	len_res = ft_get_nb_len(nb, len_base);
	res = (char *) ft_calloc(len_res + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	extract_number_base(res, len_res, nb, base);
	return (res);
}
