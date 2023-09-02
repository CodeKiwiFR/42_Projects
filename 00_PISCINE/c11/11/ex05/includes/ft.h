/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:53:38 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 21:26:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_isspace(char c);
int		ft_atoi(char *str);
int		ft_sum(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_modulo(int a, int b);
int		ft_strlen(char *str);
int		ft_is_valid_operator(char *str);
void	ft_do_op(int nb1, int nb2, char op, int (*ops[5])(int a, int b));

#endif
