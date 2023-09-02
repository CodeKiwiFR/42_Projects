/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:56:40 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 19:09:40 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(int argc, char **argv)
{
	int	size;
	char str[92];

	if (argc <= 1)
	{
		strcpy(str, "Bonjour les aminches...c. est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. ");
		str[0] = -128;
		str[20] = 9;
		str[21] = 10;
		str[22] = 9;
		str[24] = 7;
		str[33] = 9;
		str[38] = 9;
		str[63] = 9;
		str[64] = 10;
		str[65] = 9;
		str[78] = 10;
		str[79] = 10;
		str[80] = 10;
		str[81] = 9;
		str[89] = 10;

		ft_print_memory(str, 92);
	}
	else
	{
		size = atoi(argv[2]);
		ft_print_memory(argv[1], size);
	}
	return (0);
}
