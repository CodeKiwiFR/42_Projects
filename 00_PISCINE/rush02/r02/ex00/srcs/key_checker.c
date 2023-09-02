/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:52:14 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/26 19:52:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_valid_key_greater100(char *key)
{
	int	key_len;
	int	i;

	key_len = ft_strlen(key);
	if (key_len < 4 || key_len % 3 != 1)
		return (0);
	i = 0;
	while (key[i])
	{
		if ((i == 0 && key[i] != '1') || (i > 0 && key[i] != '0'))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_key_lower100(char *k)
{
	int	(*f)(char *s1, char *s2);

	f = ft_strcmp;
	if (
		!f(k, "0") || !f(k, "1") || !f(k, "2") || !f(k, "3") || !f(k, "4")
		|| !f(k, "5") || !f(k, "6") || !f(k, "7") || !f(k, "8") || !f(k, "9")
		|| !f(k, "10") || !f(k, "11") || !f(k, "12") || !f(k, "13")
		|| !f(k, "14") || !f(k, "15") || !f(k, "16") || !f(k, "17")
		|| !f(k, "18") || !f(k, "19") || !f(k, "20") || !f(k, "30")
		|| !f(k, "40") || !f(k, "50") || !f(k, "60") || !f(k, "70")
		|| !f(k, "80") || !f(k, "90") || !f(k, "100")
	)
		return (1);
	return (0);
}

int	is_valid_key(char *key)
{
	if (is_valid_key_lower100(key) || is_valid_key_greater100(key))
		return (1);
	return (0);
}
