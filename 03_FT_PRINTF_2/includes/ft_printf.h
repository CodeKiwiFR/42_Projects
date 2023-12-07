/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:50:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/07 11:00:46 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "fpf_buffer.h"
# include <stdarg.h>
# include <stdbool.h>


# include <stdio.h>

# define NB_CONVERSION 2
# define AVAILABLE_CONVERSIONS "di"
# define VALID_FORMAT "0123456789 +-#."

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

typedef struct s_format_dispatcher
{
	char	*flags;
	int		(*f)(va_list args, t_input_format *input);
}	t_format_dispatcher;

int		ft_printf(const char *format, ...);
void	init_format_dispatcher(t_format_dispatcher dispatcher[NB_CONVERSION]);

#endif
