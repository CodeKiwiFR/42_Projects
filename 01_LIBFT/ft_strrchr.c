/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:00 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 14:53:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*res;
	unsigned char	c_char;

	c_char = (unsigned char) c;
	res = (char *)s;
	while (*res != '\0')
		res++;
	while (res >= s)
	{
		if (*res == c_char)
			return (res);
		res--;
	}
	return (NULL);
}
