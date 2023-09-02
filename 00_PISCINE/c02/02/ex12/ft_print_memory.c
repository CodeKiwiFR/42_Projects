/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:54:10 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/14 10:29:13 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_printable(char c)
{
	if (c < ' ' || c == 127)
		return (0);
	return (1);
}

void	ft_print_address(void *addr)
{
	unsigned long	addr_value;
	char			addr_str[16];
	char			*hex;
	int				index;

	addr_value = (unsigned long)addr;
	hex = "0123456789abcdef";
	index = 15;
	while (index >= 0)
	{
		addr_str[index] = hex[addr_value % 16];
		addr_value /= 16;
		index--;
	}
	write(1, addr_str, 16);
	write(1, ": ", 2);
}

void	ft_print_hex_data(void *addr, unsigned int nb_bytes)
{
	char			data[39];
	unsigned int	addr_idx;
	unsigned int	data_idx;
	char			*hex;

	addr_idx = 0;
	data_idx = 0;
	hex = "0123456789abcdef";
	while (addr_idx < 16)
	{
		if (addr_idx != 0 && addr_idx % 2 == 0)
			data[data_idx++] = ' ';
		if (addr_idx < nb_bytes)
		{
			data[data_idx++] = hex[*((unsigned char *)addr + addr_idx) / 16];
			data[data_idx++] = hex[*((unsigned char *)addr + addr_idx) % 16];
		}
		else
		{
			data[data_idx++] = ' ';
			data[data_idx++] = ' ';
		}
		addr_idx++;
	}
	write(1, data, 39);
}

void	ft_print_readable_data(void *addr, unsigned int nb_bytes)
{
	unsigned int	addr_index;
	char			current_char;

	addr_index = 0;
	while (addr_index < nb_bytes)
	{
		current_char = *((char *)addr + addr_index);
		if (ft_is_printable(current_char))
			write(1, &current_char, 1);
		else
			write(1, ".", 1);
		addr_index++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	index;
	unsigned int	bytes_to_display;

	index = 0;
	while (index < size)
	{
		bytes_to_display = size - index;
		if (bytes_to_display > 16)
			bytes_to_display = 16;
		ft_print_address(addr + index);
		ft_print_hex_data(addr + index, bytes_to_display);
		write(1, " ", 1);
		ft_print_readable_data(addr + index, bytes_to_display);
		write(1, "\n", 1);
		index += 16;
	}
	return (addr);
}
