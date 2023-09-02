/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:08:55 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 09:08:36 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	array_size;
	int	i;

	array_size = max - min;
	if (array_size <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc(array_size * sizeof(int));
	if (*range == 0)
		return (-1);
	i = 0;
	while (i < array_size)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (array_size);
}

void	test(int *i)
{
	*i = 42;
}
