/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main06.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:13:27 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 20:19:55 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>            
#include <stdio.h>

void	ft_sort_string_tab(char **tab);

void	ft_disp_array(char **array)
{
	int	i;

	i = 0;
	printf("[");
	while (array[i] != 0)
	{
		printf("\"%s\"", array[i]);
		if (array[i + 1] != 0)
			printf(", ");
		i++;
	}
	printf("]\n");
}

int	main(int argc, char **argv)
{
	argv[argc - 1] = 0;
	ft_disp_array(argv);
	ft_sort_string_tab(argv);
	ft_disp_array(argv);
	return (0);
}
