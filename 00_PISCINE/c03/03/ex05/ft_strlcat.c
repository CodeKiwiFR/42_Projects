/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:37:11 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/15 09:21:15 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	cpt;

	cpt = 0;
	while (*str)
	{
		cpt++;
		str++;
	}
	return (cpt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_index;
	unsigned int	returned_value;

	dest_index = ft_strlen(dest);
	if (dest_index > size)
		return (ft_strlen(src) + size);
	returned_value = dest_index + ft_strlen(src);
	while (*src && dest_index + 1 < size)
	{
		dest[dest_index] = *src;
		src++;
		dest_index++;
	}
	dest[dest_index] = '\0';
	return (returned_value);
}
