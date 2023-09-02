/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:43:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/15 18:50:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi_base(char *str, char *base);

int	main(int argc, char **argv)
{
	int		result;
	char	*base;
	char	*number;

	if (argc > 2)
	{
		number = argv[1];
		base = argv[2];
		result = ft_atoi_base(number, base);
		printf("Result: %d\n", result);
	}
	return (0);
}
