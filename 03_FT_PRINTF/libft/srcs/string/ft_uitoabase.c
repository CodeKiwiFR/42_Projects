/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:17:16 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/11 17:34:59 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_valid_base(char *base)
{
	size_t	i;
	size_t	j;
	size_t	base_len;

	base_len = ft_strlen(base);
	i = 0;
	while (i < base_len)
	{
		if (!ft_isprint(base[i]))
			return (false);
		j = i + 1;
		while (j < base_len)
		{
			if (base[j] == base[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

char	*ft_uitoabase(unsigned int number, char *base)
{
	char	*res;
	size_t	len_base;

	if (base == NULL || !is_valid_base(base))
		return (NULL);
	len_base = ft_strlen(base);
	res = (char *) ft_calloc(33, sizeof(char));
	if (res == NULL)
		return (NULL);


	
}
