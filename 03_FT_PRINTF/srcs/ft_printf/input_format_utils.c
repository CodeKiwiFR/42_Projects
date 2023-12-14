/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_format_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:28:39 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 16:34:15 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	input_format_first_step(t_input_format *format_info, char c)
{
	if (c == '+')
		format_info->plus = true;
	if (c == '-')
		format_info->minus = true;
	if (c == '0')
		format_info->zero = true;
	if (c == '#')
		format_info->alternative = true;
	if (c == ' ')
		format_info->space = true;
}

static void	input_format_init(t_input_format *format_info)
{
	format_info->precision = false;
	format_info->precision_val = 0;
	format_info->length = 0;
	format_info->alternative = false;
	format_info->space = false;
	format_info->plus = false;
	format_info->minus = false;
	format_info->zero = false;
}

/*
#include <stdio.h>
static void DEBUG_print_format_input(t_input_format *f)
{
	printf("FORMAT: %c\n", f->format);
	printf("LEN: %zu\n", f->length);
	if (f->precision)
		printf("PRECISION ON: %zu\n", f->precision_val);
	else
		printf("PRECISION OFF: %zu\n", f->precision_val);
	if (f->alternative)
		printf("ALT ON\n");
	else
		printf("ALT OFF\n");
	if (f->space)
		printf("SPACE ON\n");
	else
		printf("SPACE OFF\n");
	if (f->plus)
		printf("PLUS ON\n");
	else
		printf("PLUS OFF\n");
	if (f->minus)
		printf("MINUS ON\n");
	else
		printf("MINUS OFF\n");
	if (f->zero)
		printf("ZERO ON\n");
	else
		printf("ZERO OFF\n");
}
*/

void	input_format_get_info(
	t_input_format *format_info,
	const char *format,
	size_t format_end
)
{
	size_t	i;

	if (format_info == NULL)
		return ;
	input_format_init(format_info);
	if (format == NULL)
		return ;
	i = 1;
	while (i <= format_end && ft_strchr("+-0# ", format[i]) != NULL)
		input_format_first_step(format_info, format[i++]);
	format_info->length = ft_atoul(format + i);
	while (i < format_end && ft_isdigit(format[i]))
		i++;
	if (i < format_end && format[i] == '.')
	{
		format_info->precision = true;
		i++;
		format_info->precision_val = ft_atoul(format + i);
	}
	format_info->format = format[format_end];
	// DEBUG_print_format_input(format_info);
}
