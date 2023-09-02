/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:32:02 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/12 17:48:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*browser;

	browser = str;
	while (*browser)
	{
		if (*browser >= 'a' && *browser <= 'z')
			*browser -= 32;
		browser++;
	}
	return (str);
}
