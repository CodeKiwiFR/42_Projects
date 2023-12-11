/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:10:27 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/11 17:32:28 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctoa(int c)
{
	char	*res;

	if (c >= 0 && c < 8)
		return (ft_strdup(""));
	res = (char *) ft_calloc(2, sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = c;
	return (res);
}
