/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:50:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/13 21:05:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "fpf_buffer.h"
# include <stdarg.h>
# include <stdbool.h>

# define NB_CONV 6
# define AVAILABLE_CONVS "discuxX%"
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

typedef struct s_format_dispatch
{
	char	*flags;
	char	*(*f)(va_list args, t_input_format *input);
}	t_format_dispatch;

char	*(*dispatch_get_func(t_format_dispatch dispatch[NB_CONV], char flag))(
			va_list args, t_input_format *input);

int		ft_printf(const char *format, ...);
void	init_format_dispatch(t_format_dispatch dispatch[NB_CONV]);

size_t	fpf_get_format_end(const char *format);
bool	fpf_is_valid_format(char c);
bool	fpf_is_available_conversion(char c);

char	*fpf_int_manager(va_list args, t_input_format *input);
char	*fpf_uint_manager(va_list args, t_input_format *input);
char	*fpf_hexa_manager(va_list args, t_input_format *input);
char	*fpf_string_manager(va_list args, t_input_format *input);
char	*fpf_char_manager(va_list args, t_input_format *input);
char	*fpf_percent_manager(va_list args, t_input_format *input);

#endif
