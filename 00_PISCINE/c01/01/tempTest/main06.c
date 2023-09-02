/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main06.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:11:35 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/10 18:54:18 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str);

int	main(void)
{
	printf("%d\n", ft_strlen("Hello World!\n"));
	printf("%d\n", ft_strlen("\n"));
	printf("%d\n", ft_strlen("No line break"));
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("BONJOUR"));
	return (0);
}
