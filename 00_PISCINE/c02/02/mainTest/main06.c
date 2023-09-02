/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main06.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:56:40 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 12:35:58 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_str_is_printable(char *str);

int	main(int argc, char **argv)
{
	int	returned;

	if (argc > 1)
	{
		returned = ft_str_is_printable(argv[1]);
		if (returned == 1)
			printf("%s => OK\n", argv[1]);
		else if (returned == 0)
			printf("%s => NOT OK\n", argv[1]);
	}
	return (0);
}
