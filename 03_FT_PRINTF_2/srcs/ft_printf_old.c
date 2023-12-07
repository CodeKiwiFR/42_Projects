/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:41:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/06 10:43:06 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	is_available_conversion(char c)
{
	return (c != '\0' && ft_strchr(AVAILABLE_CONVERSIONS, c) != NULL);
}

static bool	is_valid_format(char c)
{
	return (c != '\0' && ft_strchr(VALID_FORMAT, c) != NULL);
}

/*
static int	print_content(
		const char **format_ptr,
		va_list args,
		t_format_spec selector[NB_CONVERSION]
)
{
	const char	*format;
	size_t		i;
	size_t		j;

	format = *format_ptr;
	if (args == NULL || selector == NULL)
		return (-1);
	i = 1;
	while (format[i] != '\0' && !(i != 0 && format[i] == '%')
		&& !is_available_conversion(format[i]) && is_valid_format(format[i]))
		i++;
	if (is_available_conversion(format[i]))
	{
		*format_ptr += i;
		return (1);
	}
	j = 0;
	while (j < i)
		if (ft_putchar_fd(format[j++], 1) == -1)
			return (-1);
	*format_ptr += i;
	return (i);
}
*/

int	ft_printf(const char *format, ...)
{
	return (1);
}
