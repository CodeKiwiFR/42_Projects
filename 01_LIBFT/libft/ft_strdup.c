/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:36 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/08 18:26:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_len;

	s_len = ft_strlen(s);
	dup = (char *) malloc((s_len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, s_len + 1);
	return (dup);
}
