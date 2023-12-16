/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_string_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/16 16:06:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fpf_string_formatter_precision(
	char *str,
	t_input_format *input,
	char *ptr
)
{
	char	*res;

	if (str == NULL || input == NULL)
		return (NULL);
	res = str;
	if (input->precision)
	{
		if (ptr == NULL && input->precision_val < 6)
			res = ft_strdup("");
		else if (ptr != NULL)
			res = ft_substr(res, 0, input->precision_val);
	}
	return (res);
}

static char	*fpf_string_formatter_len(char *str, t_input_format *input)
{
	char	*res;

	if (str == NULL || input == NULL)
		return (NULL);
	res = str;
	if (input->length != 0)
	{
		if (input->minus)
			res = ft_append_chars(res, ' ', input->length);
		else
			res = ft_prepend_chars(res, ' ', input->length);
	}
	return (res);
}

static char	*fpf_string_formatter(char *str, t_input_format *input, char *ptr)
{
	char	*res;
	char	*temp;

	temp = fpf_string_formatter_precision(str, input, ptr);
	if (str == NULL || input == NULL || temp == NULL)
		return (NULL);
	res = fpf_string_formatter_len(temp, input);
	if (temp != str && temp != res)
		free(temp);
	return (res);
}

char	*fpf_string_manager(va_list args, t_input_format *input)
{
	char	*str;
	char	*res;
	char	*temp;

	if (args == NULL || input == NULL)
		return (NULL);
	str = va_arg(args, char *);
	if (str == NULL)
		temp = ft_strdup("(null)");
	else
		temp = ft_strdup(str);
	if (temp == NULL)
		return (NULL);
	res = fpf_string_formatter(temp, input, str);
	if (temp != res)
		free(temp);
	return (res);
}
