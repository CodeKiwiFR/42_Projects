/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:48:36 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/13 20:08:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("Original : %d\n", strcmp(argv[1], argv[2]));
		printf("Custom   : %d\n", strcmp(argv[1], argv[2]));
	}
	return (0);
}
