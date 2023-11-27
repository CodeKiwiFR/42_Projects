/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:41:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/27 17:24:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_available_conversion(char c)
{
	return (c != '\0' && ft_strchr(AVAILABLE_CONVERSIONS, c) != NULL);
}

static int	print_content(const char **format_ptr, va_list args, t_format_spec selector[NB_CONVERSION])
{
	const char	*format;
	size_t		i;
	size_t		j;

	format = *format_ptr;
	if (args == NULL || selector == NULL)
		return (-1);
	i = 0;
	while (format[i] != '\0' && !(i != 0 && format[i] == '%') && !is_available_conversion(format[i]))
		i++;
	if (is_available_conversion(format[i]))
	{
		// Deal with given flag
		*format_ptr += i;
		return (1);
	}
	j = 0;
	while (j < i)
		ft_putchar_fd(format[j++], 1);
	*format_ptr += i;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_format_spec	selector[NB_CONVERSION];
	int				count;
	
	init_format_spec(selector);
	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_content(&format, args, selector);
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}
