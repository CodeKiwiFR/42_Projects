/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:41:46 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/23 15:44:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list				args;
	size_t				i;
	t_format_specifier	*selector;
	int					count;
	
	va_start(args, format);
	count = 0;
	selector = NULL;
	i = 0;
	while (format[i] != '\0')
	{
		ft_putchar_fd(format[i], 1);
		i++;
	}
	return (count);
}
