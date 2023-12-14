/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:41:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 14:17:35 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_formatted_content(
	const char *format,
	va_list args,
	t_format_dispatch dispatch[NB_CONV],
	t_fpf_buffer *buffer
)
{
	size_t			format_end;
	char			*(*f)(va_list args, t_input_format *input);
	char			*res;
	t_input_format	format_info;

	if (buffer == NULL)
		return ;
	if (format == NULL || args == NULL || dispatch == NULL)
		return (buffer->set_error(buffer));
	format_end = fpf_get_format_end(format);
	if (format_end == 0)
		return (buffer->set_error(buffer));
	f = dispatch_get_func(dispatch, format[format_end]);
	if (f == NULL)
		return (buffer->set_error(buffer));
	//input_format_get_info(&format_info, format, format_end);
	res = f(args, &format_info);
	if (res == NULL)
		return (buffer->set_error(buffer));
	if (format[format_end] == 'c' && ft_strlen(res) == 0)
		buffer->add_char_secure(buffer, 0, 1);
	else
		buffer->add_str_secure(buffer, res, 1);
	free(res);
}

static void	print_content(
	const char **format_ptr,
	va_list args,
	t_format_dispatch dispatch[NB_CONV],
	t_fpf_buffer *buffer
)
{
	const char	*format;
	size_t		i;
	size_t		j;

	format = *format_ptr;
	if (buffer == NULL)
		return ;
	if (args == NULL || dispatch == NULL)
		return (buffer->set_error(buffer));
	i = fpf_get_format_end(format);
	if (fpf_is_available_conversion(format[i]))
	{
		print_formatted_content(format, args, dispatch, buffer);
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
	t_format_dispatch	dispatch[NB_CONV];
	va_list				args;

	buffer = buffer_init();
	init_format_dispatch(dispatch);
	va_start(args, format);
	while (*format != '\0' && !buffer.error)
	{
		if (*format == '%')
		{
			print_content(&format, args, dispatch, &buffer);
			continue ;
		}
		buffer.add_char_secure(&buffer, *format, 1);
		format++;
	}
	buffer.put_fd(&buffer, 1);
	if (buffer.error == true)
		return (-1);
	return ((int) buffer.total_len);
}
