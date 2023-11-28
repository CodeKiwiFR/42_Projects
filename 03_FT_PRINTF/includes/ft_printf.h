/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:50:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/28 20:04:45 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"


# include <stdio.h>

# define NB_CONVERSION 2
# define AVAILABLE_CONVERSIONS "di"
# define VALID_FORMAT "0123456789 +-#."
# define BUFFER_SIZE 1000

typedef struct s_flags_manager
{
	size_t	precision;
	size_t	length;
	bool	alternative;
	bool	space;
	bool	plus;
	bool	minus;
	bool	zero;
	char	conversion;
}	t_flags_manager;

typedef struct s_format_specifier
{
	char	flag;
	int		(*f)(va_list args, t_flags_manager *input);
}	t_format_specifier;

typedef struct s_buffer
{
	char	content[BUFFER_SIZE];
	size_t	next_index;
	size_t	total_len;
	void	(*add_string)(struct s_buffer *buffer, char *str);
	void	(*add_char)(struct s_buffer *buffer, char c);
	void	(*flush)(struct s_buffer *buffer);
	ssize_t	(*put_fd)(struct s_buffer * buffer, int fd);
	bool	(*is_full)(struct s_buffer * buffer);
	bool	(*is_addable)(struct s_buffer * buffer, size_t len);
}	t_buffer;

int		ft_printf(const char *format, ...);
void	init_format_specifier(t_format_specifier format[NB_CONVERSION]);

void	buffer_add_char(t_buffer *buffer, char c);
void	buffer_add_string(t_buffer *buffer, char *str);
void	buffer_flush(t_buffer *buffer);
ssize_t	buffer_put_fd(t_buffer *buffer, int fd);
bool	buffer_is_full(t_buffer *buffer);
bool	buffer_is_addable(t_buffer *buffer, size_t len);

#endif
