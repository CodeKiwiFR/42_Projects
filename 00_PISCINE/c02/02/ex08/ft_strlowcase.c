/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:59:49 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/12 18:01:22 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*browser;

	browser = str;
	while (*browser)
	{
		if (*browser >= 'A' && *browser <= 'Z')
			*browser += 32;
		browser++;
	}
	return (str);
}
