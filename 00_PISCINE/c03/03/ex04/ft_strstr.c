/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:29:54 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/15 07:31:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	if (*str == '\0')
		return (0);
	if (*str == *to_find && ft_strstr(str + 1, to_find + 1) == str + 1)
		return (str);
	else
		return (ft_strstr(str + 1, to_find));
}
