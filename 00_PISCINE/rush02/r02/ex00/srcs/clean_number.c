/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:00:08 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/27 21:10:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*skip_zeros(char *number)
{
	int	number_len;

	number_len = ft_strlen(number);
	if (number_len == 0)
		return (NULL);
	if (number_len == 1 && *number == '0')
		return (number);
	while (*number && *number == '0')
		number++;
	if (*number == '\0')
		return (number - 1);
	return (number);
}

char	*clean_number(char *number)
{
	int		number_len;
	char	*number_end;
	int		sign;

	number_len = ft_strlen(number);
	if (number_len == 0)
		return (NULL);
	while (*number && ft_isspace(*number))
		number++;
	sign = 1;
	while (*number && (*number == '+' || *number == '-'))
	{
		if (*number == '-')
			sign *= -1;
		number++;
	}
	if (sign == -1)
		return (NULL);
	number_end = number;
	while (*number_end && *number_end >= '0' && *number_end <= '9')
		number_end++;
	if (*number_end != '\0')
		return (NULL);
	return (skip_zeros(number));
}

int	get_number_cleaned(char **number, t_translation *dict)
{
	*number = clean_number(*number);
	if (*number == NULL)
	{
		ft_putstr_error("Error\n");
		if (dict != NULL)
			clean_memory_dict(dict);
		return (0);
	}
	return (1);
}
