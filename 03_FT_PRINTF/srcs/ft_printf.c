/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:41:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/25 15:47:16 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_content(char **str, va_list args, t_format_spec selector[NB_CONVERSION])
{
	return (1);
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
		{
			count += print_content((char **) &format, args, selector);
			format++;
		}
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
