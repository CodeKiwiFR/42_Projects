/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:09:20 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/18 01:33:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(int argc, char **argv)
{
	char	*nbr;
	char	*base_from;
	char	*base_to;
	char	*result;

	if (argc == 4)
	{
		nbr = argv[1];
		base_from = argv[2];
		base_to = argv[3];
		result = ft_convert_base(nbr, base_from, base_to);
		if (!result)
		{
			printf("ERROR - The function returned an error\n");
			return (0);
		}
		printf("Result: \"%s\"\n", result);
		free(result);
	}
	return (0);
}
