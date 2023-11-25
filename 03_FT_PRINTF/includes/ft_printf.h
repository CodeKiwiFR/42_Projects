/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:50:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/25 15:35:25 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define NB_CONVERSION 1

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

typedef struct s_format_spec
{
	char	flag;
	int		(*f)(va_list args, t_input_format *input);
}	t_format_spec;

int		ft_printf(const char *format, ...);
void	init_format_spec(t_format_spec format[NB_CONVERSION]);

#endif
