/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 07:29:08 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/09 07:36:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	digit_to_display;

	digit_to_display = '0';
	while (digit_to_display <= '9')
	{
		write(1, &digit_to_display, 1);
		digit_to_display++;
	}
	return ;
}
