/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_uint_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/15 14:22:22 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fpf_uint_formatter_precision(char *str, t_input_format *input)
{
	char	*res;

	if (str == NULL || input == NULL)
		return (NULL);
	res = str;
	if (input->precision)
	{
		res = ft_prepend_chars(res, '0', input->precision_val);
		if (res == NULL)
			return (NULL);
	}
	return (res);
}

static char	*fpf_uint_formatter_length(char *str, t_input_format *input)
{
	char	*res;

	if (str == NULL || input == NULL)
		return (NULL);
	res = str;
	if (input->length > 0)
	{
		if (input->minus)
			res = ft_append_chars(res, ' ', input->length);
		else if (!input->precision && input->zero)
			res = ft_prepend_chars(res, '0', input->length);
		else
			res = ft_prepend_chars(res, ' ', input->length);
	}
	return (res);
}

static char	*fpf_uint_formatter(char *str, t_input_format *input)
{
	char	*temp;
	char	*res;

	temp = fpf_uint_formatter_precision(str, input);
	if (str == NULL || input == NULL || temp == NULL)
		return (NULL);
	res = fpf_uint_formatter_length(temp, input);
	if (temp != str && temp != res)
		free(temp);
	return (res);
}

char	*fpf_uint_manager(va_list args, t_input_format *input)
{
	unsigned int	nb;
	char			*res;
	char			*temp;

	if (args == NULL || input == NULL)
		return (NULL);
	nb = va_arg(args, unsigned int);
	temp = ft_ltoa((long) nb);
	if (temp == NULL)
		return (NULL);
	res = fpf_uint_formatter(temp, input);
	if (temp != res)
		free(temp);
	return (res);
}
