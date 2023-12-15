/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_uint_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/15 17:28:07 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fpf_uint_formatter(char *str, t_input_format *input)
{
	char	*temp;
	char	*res;

	temp = fpf_formatter_precision(str, input);
	if (str == NULL || input == NULL || temp == NULL)
		return (NULL);
	res = fpf_formatter_length(temp, input);
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
