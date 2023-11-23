/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:50:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/23 14:42:13 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_intput_format
{
	size_t	precision;
	size_t	length;
	bool	alternative;
	bool	space;
	bool	plus;
	bool	minus;
	bool	zero;
}	t_input_format;

typedef struct s_format_specifier
{
	char	flag;
	int		(*f)(va_list args, t_input_format *input);
}	t_format_specifier;

int	ft_printf(const char *format, ...);

#endif
