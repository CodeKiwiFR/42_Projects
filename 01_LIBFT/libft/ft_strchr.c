/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:34 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 14:43:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *)s;
	while (*res != '\0')
	{
		if (*res == (unsigned char) c)
			return (res);
		res++;
	}
	return (NULL);
}
