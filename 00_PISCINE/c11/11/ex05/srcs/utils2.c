/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:47:06 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 21:26:17 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_is_valid_operator(char *str)
{
	char	op;

	if (ft_strlen(str) != 1)
		return (0);
	op = str[0];
	if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
		return (0);
	return (1);
}

void	ft_do_op(int nb1, int nb2, char op, int (*ops[5])(int a, int b))
{
	if (op == '+')
		ft_putnbr(ops[0](nb1, nb2));
	else if (op == '-')
		ft_putnbr(ops[1](nb1, nb2));
	else if (op == '*')
		ft_putnbr(ops[2](nb1, nb2));
	else if (op == '/')
	{
		if (nb2 == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr(ops[3](nb1, nb2));
	}
	else
	{
		if (nb2 == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(ops[4](nb1, nb2));
	}
	ft_putchar('\n');
}
