/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:20:43 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 15:22:21 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

int	ft_read_and_print_file(int fd);
int	ft_check_flags(int argc, char **argv);
int	ft_open_error(char *file_name);
int	ft_read_all_files(int argc, char **argv);
int	ft_putchar(char c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_strlen(char *str);
int	ft_file_name_need_quotes(char *file_name);
int	ft_isspace(char c);

#endif
