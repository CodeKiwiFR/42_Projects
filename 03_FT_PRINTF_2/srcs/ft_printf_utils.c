/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:31:18 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/08 16:50:15 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	fpf_is_available_conversion(char c)
{
	return (c != '\0' && ft_strchr(AVAILABLE_CONVS, c) != NULL);
}

bool	fpf_is_valid_format(char c)
{
	return (c != '\0' && ft_strchr(VALID_FORMAT, c) != NULL);
}

size_t	fpf_get_format_end(const char *format)
{
	size_t	i;

	if (format == NULL)
		return (0);
	i = 1;
	while (format[i] != '\0' && !(i != 0 && format[i] == '%')
		&& !fpf_is_available_conversion(format[i])
		&& fpf_is_valid_format(format[i]))
		i++;
	return (i);
}
