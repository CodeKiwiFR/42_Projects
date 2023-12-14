/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_string_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 18:45:16 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fpf_string_formatter(char *str, t_input_format *input)
{
	char	*res;
	char	*temp;

	if (str == NULL || input == NULL)
		return (NULL);
	temp = str;
	res = str;
	if (input->precision)
	{
		temp = ft_substr(str, 0, input->precision_val);
		if (temp == NULL)
			return (NULL);
		res = temp;
	}
	if (input->length != 0)
	{
		if (input->minus)
			res = ft_append_chars(temp, ' ', input->length);
		else
			res = ft_prepend_chars(temp, ' ', input->length);
		if (temp != str)
			free(temp);
	}
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
	res = fpf_string_formatter(temp, input);
	if (temp != res)
		free(temp);
	return (res);
}
