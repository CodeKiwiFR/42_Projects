/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:57 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/14 14:00:21 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_file_storage
{
	int		fd;
	char	*buffer_remaining;
}	t_file_storage;

char	*get_next_line(int fd);

#endif
