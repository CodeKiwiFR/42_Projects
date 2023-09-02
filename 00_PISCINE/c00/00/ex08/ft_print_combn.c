/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 07:44:29 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/10 12:19:40 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

short	ft_is_a_valid_comb(int number)
{
	int	last_digit;
	int	prev_digit;

	prev_digit = number % 10;
	while (number > 0)
	{
		last_digit = prev_digit;
		prev_digit = (number / 10) % 10;
		if (last_digit <= prev_digit)
			return (0);
		number /= 10;
	}
	return (1);
}

void	ft_print_comb_displayer(int number, int size)
{
	int		multiplier;
	char	char_to_display;

	multiplier = 1;
	while (size > 1)
	{
		multiplier *= 10;
		size--;
	}
	while (multiplier > 0)
	{
		char_to_display = (char)(number / multiplier) + '0';
		write(1, &char_to_display, 1);
		number = number % multiplier;
		multiplier /= 10;
	}
	return ;
}

int	ft_get_minimum_int(int size)
{
	if (size == 1)
		return (0);
	if (size == 2)
		return (1);
	if (size == 3)
		return (12);
	if (size == 4)
		return (123);
	if (size == 5)
		return (1234);
	if (size == 6)
		return (12345);
	if (size == 7)
		return (123456);
	if (size == 8)
		return (1234567);
	if (size == 9)
		return (12345678);
	return (0);
}

int	ft_get_maximum_int(int size)
{
	if (size == 1)
		return (9);
	if (size == 2)
		return (89);
	if (size == 3)
		return (789);
	if (size == 4)
		return (6789);
	if (size == 5)
		return (56789);
	if (size == 6)
		return (456789);
	if (size == 7)
		return (3456789);
	if (size == 8)
		return (23456789);
	if (size == 9)
		return (123456789);
	return (0);
}

void	ft_print_combn(int n)
{
	int		number;
	int		limit;

	number = ft_get_minimum_int(n);
	limit = ft_get_maximum_int(n);
	while (number <= limit)
	{
		if (ft_is_a_valid_comb(number) == 1)
		{
			ft_print_comb_displayer(number, n);
			if (number != limit)
			{
				write(1, ",", 1);
				write(1, " ", 1);
			}
		}
		number++;
	}
	return ;
}
