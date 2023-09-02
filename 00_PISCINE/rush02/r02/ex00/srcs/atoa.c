/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:08:39 by gurousta          #+#    #+#             */
/*   Updated: 2023/08/26 18:34:53 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_allocate_memory(unsigned int i, unsigned int *byte)
{
	char	*result;

	if (i == *byte)
	{
		result = (char *)malloc(sizeof(char) * 2);
		if (*byte != 0)
			--(*byte);
	}
	else
		result = (char *)malloc(sizeof(char) * ((i - *byte) + 1));
	if (!result)
		return (NULL);
	return (result);
}

int	ft_is_only_char(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

void	ft_strcpy_atoa(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	if (ft_is_only_char(src[0]))
	{
		dest[0] = '0';
		dest[1] = '\0';
		return ;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
}

char	*ft_atoa(char *str)
{
	unsigned int	i;
	unsigned int	byte;
	char			*result;

	i = 0;
	if (!ft_strlen(str))
		return (NULL);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (NULL);
		++i;
	}
	while (str[i] == '0')
		++i;
	byte = i;
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	result = ft_allocate_memory(i, &byte);
	if (!result)
		return (NULL);
	ft_strcpy_atoa(result, str + byte);
	return (result);
}
