/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_char_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 18:15:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fpf_char_formatter(char *str, t_input_format *input)
{
	if (input->length == 0)
		return (str);
	if (input->minus)
		return (ft_append_chars(str, ' ', input->length));
	return (ft_prepend_chars(str, ' ', input->length));
}

char	*fpf_char_manager(va_list args, t_input_format *input)
{
	char	c;
	char	*str;
	char	*res;

	if (args == NULL || input == NULL)
		return (NULL);
	c = va_arg(args, int);
	str = ft_ctoa(c);
	if (str == NULL)
		return (NULL);
	res = fpf_char_formatter(str, input);
	if (str != res)
		free(str);
	return (res);
}
