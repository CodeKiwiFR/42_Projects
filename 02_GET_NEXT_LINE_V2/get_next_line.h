/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:57 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/20 14:51:02 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>



#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_buffer_save
{
	int		fd;
	char	*buffer;
}	t_buffer_save;


char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		gnl_join(char **s1, char *s2);


// TO REMOVE OR SET TO STATIC
char	*store_get_buffer(t_list **store, int fd);
int		store_save(t_list **store, char *buffer, int fd);

#endif
