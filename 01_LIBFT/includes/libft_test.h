/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:14:00 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/09 09:30:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# include "libft.h"
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>

void	print_test_intro(char *func_name);
void	print_test_infos(int test_index, int test_success, int is_last);
void	print_red(char *str);
void	print_green(char *str);

void	test_isalpha(void);
void	test_isdigit(void);
void	test_isalnum(void);
void	test_isascii(void);
void	test_isprint(void);
void	test_atoi(void);

void	test_strlen(void);
void	test_strlcpy(void);
void	test_strlcat(void);
void	test_toupper(void);
void	test_tolower(void);
void	test_strlcpy(void);
void	test_strlcat(void);
void	test_strchr(void);
void	test_strrchr(void);
void	test_strncmp(void);
void	test_strnstr(void);
void	test_strdup(void);

void	test_calloc(void);
void	test_memset(void);
void	test_bzero(void);
void	test_memcpy(void);
void	test_memmove(void);
void	test_memchr(void);
void	test_memcmp(void);

#endif
