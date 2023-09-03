/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_charset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:17:44 by pbigot            #+#    #+#             */
/*   Updated: 2023/08/30 19:36:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_printable(char c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}

char	*get_charset(char *str)
{
	char	*charset;
	int		count;
	int		len;

	charset = (char *)malloc(4 * sizeof(char));
	if (!charset)
		return (0);
	count = 0;
	while (str[count] && str[count] != '\n' && is_printable(str[count]))
		count++;
	len = ft_strlen(str + count);
	if (count == 0 || len < 3)
	{
		free(charset);
		return (0);
	}
	charset[0] = str[count - 3];
	charset[1] = str[count - 2];
	charset[2] = str[count - 1];
	charset[3] = 0;
	return (charset);
}
