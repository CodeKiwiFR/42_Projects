/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:30:13 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/21 16:46:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_space(char c)
{
	if (
		c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v'
	)
		return (1);
	return (0);
}

int	ft_index_of(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_base_valid(char c)
{
	if (c > ' ' && c <= '~' && c != '+' && c != '-')
		return (1);
	return (0);
}

long	ft_check_base(char *base)
{
	long	i;
	long	j;

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

char	*ft_prepend(char *dest, char c, int dest_len)
{
	char	*temp;
	int		i;

	if (dest == 0)
		return (0);
	temp = (char *)malloc((dest_len + 1) * sizeof(char));
	if (!temp)
		return (0);
	temp[0] = c;
	i = 1;
	while (i < dest_len && dest[i - 1] != '\0')
	{
		temp[i] = dest[i - 1];
		i++;
	}
	temp[dest_len] = '\0';
	free(dest);
	return (temp);
}
