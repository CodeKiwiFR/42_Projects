/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:34:41 by gurousta          #+#    #+#             */
/*   Updated: 2023/08/27 22:27:29 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi_n(char *str, unsigned int n)
{
	unsigned int	i;
	int				result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < n)
	{
		result = result * 10 + (str[i] - '0');
		++i;
	}
	return (result);
}

int	ft_eval_size(int nb)
{
	int	size;

	size = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_pos(int nb)
{
	char	*res;
	int		nb_size;
	int		i;

	nb_size = ft_eval_size(nb);
	res = (char *)malloc((nb_size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = nb_size - 1;
	while (i >= 0)
	{
		res[i] = ((char)(nb % 10)) + '0';
		nb /= 10;
		i--;
	}
	res[nb_size] = '\0';
	return (res);
}

int	ft_get_byte(char **strs)
{
	int	byte;
	int	i;

	i = 0;
	byte = 0;
	while (strs[i])
	{
		byte += ft_strlen(strs[i]);
		++i;
	}
	byte += i - 1;
	return (byte);
}

char	*ft_strjoin(char **strs)
{
	char	*result;
	int		byte;
	int		i;

	i = 0;
	byte = ft_get_byte(strs);
	result = (char *)malloc(sizeof(char) * (byte + 1));
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strcat(result, strs[i++]);
	while (strs[i])
	{
		ft_strcat(result, " ");
		ft_strcat(result, strs[i]);
		i++;
	}
	return (result);
}
