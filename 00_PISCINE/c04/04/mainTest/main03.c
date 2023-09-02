/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:43:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/15 15:30:34 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(char *str);

int	main(int argc, char **argv)
{
	int	returned_lib;
	int	returned_mine;
	if (argc > 1)
	{
		returned_lib = atoi(argv[1]);
		returned_mine = ft_atoi(argv[1]);
		printf("LIB : %d\n", returned_lib);
		printf("MINE: %d\n", returned_mine);
	}
	return (0);
}
