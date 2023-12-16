/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_hexa_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/16 16:51:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fpf_hexa_formatter_precision(
	char *str,
	t_input_format *input,
	unsigned int nb
)
{
	char	*res;

	if (str == NULL || input == NULL)
		return (NULL);
	res = str;
	if (input->precision)
	{
		if (nb == 0 && input->precision_val == 0)
			res = ft_strdup("");
		else
			res = ft_prepend_chars(res, '0', input->precision_val);
	}
	else if (input->zero && !input->minus)
	{
		if (input->alternative && input->length >= 2)
			res = ft_prepend_chars(res, '0', input->length - 2);
		else if (!input->alternative)
			res = ft_prepend_chars(res, '0', input->length);
	}
	return (res);
}

static char	*fpf_hexa_formatter_alt(char *str, t_input_format *input)
{
	char	*res;

	if (str == NULL || input == NULL)
		return (NULL);
	res = str;
	if (input->alternative)
	{
		if (input->format == 'x')
			res = ft_strjoin("0x", res);
		else
			res = ft_strjoin("0X", res);
	}
	return (res);
}

static char	*fpf_hexa_formatter_length(char *str, t_input_format *input)
{
	char	*res;

	if (str == NULL || input == NULL)
		return (NULL);
	res = str;
	if (input->length > 0)
	{
		if (input->minus)
			res = ft_append_chars(res, ' ', input->length);
		else
			res = ft_prepend_chars(res, ' ', input->length);
	}
	return (res);
}

static char	*fpf_hexa_formatter(
	char *str,
	t_input_format *input,
	unsigned int nb
)
{
	char	*res;
	char	*temp;

	if (input != NULL && nb == 0)
		input->alternative = false;
	temp = fpf_hexa_formatter_precision(str, input, nb);
	if (str == NULL || input == NULL || temp == NULL)
		return (NULL);
	res = fpf_hexa_formatter_alt(temp, input);
	if (temp != res && temp != str)
		free(temp);
	if (res == NULL)
		return (NULL);
	temp = res;
	res = fpf_hexa_formatter_length(temp, input);
	if (temp != res && temp != str)
		free(temp);
	return (res);
}

char	*fpf_hexa_manager(va_list args, t_input_format *input)
{
	unsigned int		nb;
	char				*temp;
	char				*res;

	if (args == NULL || input == NULL)
		return (NULL);
	nb = va_arg(args, unsigned int);
	if (input->format == 'x')
		temp = ft_ltoa_base(nb, "0123456789abcdef");
	else
		temp = ft_ltoa_base(nb, "0123456789ABCDEF");
	if (temp == NULL)
		return (NULL);
	res = fpf_hexa_formatter(temp, input, nb);
	if (temp != res)
		free(temp);
	return (res);
}
