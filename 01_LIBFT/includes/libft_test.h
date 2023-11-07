/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:14:00 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/07 10:55:31 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# include "libft.h"
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>

void	print_test_intro(char *func_name);
void	print_test_infos(int test_index, int test_success, int is_last);

void	test_isalpha(void);
void	test_isdigit(void);

#endif
