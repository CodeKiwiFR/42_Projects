/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_ptr_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/15 13:35:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fpf_ptr_formatter_precision(char *str, t_input_format *input)
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
	else if (input->length >= 2 && input->zero && !input->minus)
	{
		res = ft_prepend_chars(res, '0', input->length - 2);
		if (res == NULL)
			return (NULL);
	}
	return (res);
}

static char	*fpf_ptr_formatter(char *str, t_input_format *input)
{
	char	*temp;
	char	*res;

	temp = fpf_ptr_formatter_precision(str, input);
	if (str == NULL || input == NULL || temp == NULL)
		return (NULL);
	res = temp;
	res = ft_strjoin("0x", temp);
	if (temp != str)
		free(temp);
	if (res == NULL)
		return (NULL);
	if (input->length > 0)
	{
		temp = res;
		if (input->minus)
			res = ft_append_chars(temp, ' ', input->length);
		else
			res = ft_prepend_chars(temp, ' ', input->length);
		free(temp);
	}
	return (res);
}

static char	*fpf_ptr_formatter_nil(char *str, t_input_format *input)
{
	char	*res;

	if (str == NULL || input == NULL)
		return (NULL);
	res = str;
	if (input->length > 0)
	{
		if (input->minus)
			res = ft_append_chars(str, ' ', input->length);
		else
			res = ft_prepend_chars(str, ' ', input->length);
	}
	return (res);
}

char	*fpf_ptr_manager(va_list args, t_input_format *input)
{
	void	*ptr;
	char	*res;
	char	*temp;

	if (args == NULL || input == NULL)
		return (NULL);
	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		temp = ft_strdup("(nil)");
		if (temp == NULL)
			return (NULL);
		res = fpf_ptr_formatter_nil(temp, input);
	}
	else
	{
		temp = ft_ultoa_base((unsigned long) ptr, "0123456789abcdef");
		if (temp == NULL)
			return (NULL);
		res = fpf_ptr_formatter(temp, input);
	}
	if (temp != res)
		free(temp);
	return (res);
}
