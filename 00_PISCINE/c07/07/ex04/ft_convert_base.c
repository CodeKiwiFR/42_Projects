/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:04:16 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/21 17:02:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_space(char c);
int		ft_index_of(char c, char *base);
int		ft_is_base_valid(char c);
long	ft_check_base(char *base);
char	*ft_prepend(char *dest, char c, int dest_len);

long	ft_atoi_base(char *nbr, char *base, int base_len)
{
	long	number;
	int		char_index;

	number = 0;
	while (*nbr)
	{
		char_index = ft_index_of(*nbr, base);
		if (char_index == -1)
			return (number);
		number *= base_len;
		number += char_index;
		nbr++;
	}
	return (number);
}

char	*ft_itoa_base(long number, char *base, int base_len)
{
	char	*res;
	int		res_len;
	int		sign;

	sign = 1;
	if (number < 0)
	{
		sign = -1;
		number *= -1;
	}
	res = (char *)malloc(sizeof(char));
	if (!res)
		return (0);
	res[0] = '\0';
	if (number == 0)
		return (ft_prepend(res, base[0], 1));
	res_len = 1;
	while (number != 0 && res != 0)
	{
		res = ft_prepend(res, base[number % base_len], res_len++);
		number /= base_len;
	}
	if (sign == -1 && res != 0)
		return (ft_prepend(res, '-', res_len));
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_len;
	int		base_to_len;
	int		sign;
	long	number;
	char	*result;

	base_from_len = ft_check_base(base_from);
	base_to_len = ft_check_base(base_to);
	if (base_from_len == -1 || base_to_len == -1)
		return (0);
	while (ft_is_space(*nbr))
		nbr++;
	sign = 1;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	number = sign * ft_atoi_base(nbr, base_from, base_from_len);
	result = ft_itoa_base(number, base_to, base_to_len);
	return (result);
}
