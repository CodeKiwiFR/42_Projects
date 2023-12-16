/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_formatter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:24:38 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/16 16:19:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fpf_formatter_precision(char *str, t_input_format *input, int nb)
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
	return (res);
}

char	*fpf_formatter_length(char *str, t_input_format *input)
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
