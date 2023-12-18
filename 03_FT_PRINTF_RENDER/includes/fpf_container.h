/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_container.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:44:15 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/18 17:09:04 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPF_CONTAINER_H
# define FPF_CONTAINER_H

# include "libft.h"
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>

# define FPF_CONTAINER_SIZE 1000

typedef struct s_fpf_container
{
	char	content[FPF_CONTAINER_SIZE];
	size_t	max_size;
	size_t	next_index;
	size_t	total_len;
	bool	error;
	void	(*flush)(struct s_fpf_container *container);
	size_t	(*get_available_size)(struct s_fpf_container * container);
	void	(*set_error)(struct s_fpf_container *container);
	void	(*add_char)(struct s_fpf_container *container, char c);
	void	(*add_char_secure)(
			struct s_fpf_container *container, char c, int fd);
	void	(*add_chars_secure)(
			struct s_fpf_container *container, char *str, size_t nb_chars,
			int fd);
	void	(*add_str)(struct s_fpf_container *container, char *str);
	void	(*add_str_secure)(
			struct s_fpf_container *container, char *str, int fd);
	void	(*put_fd)(struct s_fpf_container *container, int fd);
}	t_fpf_container;

t_fpf_container	container_init(void);
void			container_flush(t_fpf_container *container);
size_t			container_get_available_size(t_fpf_container *container);
void			container_set_error(t_fpf_container *container);
void			container_add_char(t_fpf_container *container, char c);
void			container_add_char_secure(
					t_fpf_container *container,
					char c,
					int fd
					);
void			container_add_chars_secure(
					t_fpf_container *container,
					char *str,
					size_t nb_chars,
					int fd
					);
void			container_add_str(t_fpf_container *container, char *str);
void			container_add_str_secure(
					t_fpf_container *container,
					char *str,
					int fd
					);
void			container_put_fd(t_fpf_container *container, int fd);

#endif
