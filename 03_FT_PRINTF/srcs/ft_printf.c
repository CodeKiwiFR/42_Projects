/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:41:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/24 17:21:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list				args;
	t_format_specifier	*selector;
	int					count;
	
	selector = init_format_specifier();
	if (selector == NULL)
		return (0);
	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_formatted_content(format, args, selector);
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	free_format_specifier(selector);
	va_end(args);
	return (count);
}
