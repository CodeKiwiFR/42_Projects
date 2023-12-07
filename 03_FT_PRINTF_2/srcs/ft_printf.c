/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:41:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/07 19:49:00 by mhotting         ###   ########.fr       */
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

static size_t	get_format_end(char *format)
{
	size_t	i;

	if (format == NULL)
		return (0);
	i = 1;
	while (format[i] != '\0' && !(i != 0 && format[i] == '%')
		&& !is_available_conversion(format[i]) && is_valid_format(format[i]))
		i++;
	return (i);
}

static void	print_content(
	const char **format_ptr,
	va_list args,
	t_format_dispatcher dispatcher[NB_CONVERSION],
	t_fpf_buffer *buffer
)
{
	const char	*format;
	size_t		i;
	size_t		j;

	format = *format_ptr;
	if (args == NULL || dispatcher == NULL || buffer == NULL)
		return ;
	i = get_format_end(format);
	if (is_available_conversion(format[i]))
	{
		//returned = print_content_formatted(format, i, dispatcher, args);
		*format_ptr += i + 1;
		return ;
	}
	j = 0;
	while (j < i)
		buffer->add_char_secure(buffer, format[j++], 1);
	*format_ptr += i;
}

int	ft_printf(const char *format, ...)
{
	t_fpf_buffer		buffer;
	t_format_dispatcher	dispatcher[NB_CONVERSION];
	va_list				args;

	buffer = buffer_init();
	init_format_dispatcher(dispatcher);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			print_content(&format, args, dispatcher, &buffer);
			continue;
		}
		buffer.add_char_secure(&buffer, *format, 1);
		format++;
	}
	buffer.put_fd(&buffer, 1);
	if (buffer.error == true)
		return (-1);
	return ((int) buffer.total_len);
}
