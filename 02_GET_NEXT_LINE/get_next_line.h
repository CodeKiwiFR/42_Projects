/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:57 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/20 10:07:55 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	clear_buffer(char buffer[BUFFER_SIZE + 1]);
char	**gnl_split(char *str, int *nl_found);
int		gnl_join(char **s1, char *s2);
void	clear_memory(char **res, char **store, char **split_result);

#endif
