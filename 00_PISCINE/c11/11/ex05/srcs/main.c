/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:46:28 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/29 21:52:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int		nb1;
	int		nb2;
	char	op;
	int		(*ops[5])(int a, int b);

	ops[0] = &ft_sum;
	ops[1] = &ft_sub;
	ops[2] = &ft_mul;
	ops[3] = &ft_div;
	ops[4] = &ft_modulo;
	if (argc == 4)
	{
		nb1 = ft_atoi(argv[1]);
		nb2 = ft_atoi(argv[3]);
		if (!ft_is_valid_operator(argv[2]))
		{
			ft_putnbr(0);
			ft_putchar('\n');
			return (0);
		}
		op = argv[2][0];
		ft_do_op(nb1, nb2, op, ops);
	}
	return (0);
}
