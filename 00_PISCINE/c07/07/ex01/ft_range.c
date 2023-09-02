/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:58:41 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/17 22:03:25 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	array_size;
	int	i;

	if (min >= max)
		return (0);
	array_size = max - min;
	array = (int *)malloc(array_size * sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (i < array_size)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}
