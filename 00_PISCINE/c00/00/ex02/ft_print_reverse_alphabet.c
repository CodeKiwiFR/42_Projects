/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:29:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/09 07:59:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	char_to_display;

	char_to_display = 'z';
	while (char_to_display >= 'a')
	{
		write(1, &char_to_display, 1);
		char_to_display--;
	}
}
