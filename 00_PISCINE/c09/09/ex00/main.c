/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:59:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/25 13:41:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 30;
	if (argc > 1)
	{
		printf("Before: %d AND %d\n", i, j);
		ft_swap(&i, &j);
		printf("After : %d AND %d\n", i, j);
	}
	if (argv)
		return (0);
	return (0);
}
