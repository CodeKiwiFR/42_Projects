/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:04:44 by pbigot            #+#    #+#             */
/*   Updated: 2023/08/30 20:19:15 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_characters(char *charset)
{
	int	i;
	int	j;

	if (ft_strlen(charset) != 3)
		return (0);
	i = 0;
	while (charset[i])
	{
		j = i + 1;
		while (charset[j])
		{
			if (charset[i] == charset[j])
				return (0);
			j++;
		}
		i++;
	}
	if (!is_valid_char(charset))
		return (0);
	return (1);
}

int	check_line_nbr(int lines, int cols, char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	if (size / cols != lines || size % cols != 0)
		return (0);
	return (1);
}

int	length_compare(char *string_file, int count, int i, int last_count)
{
	int	string_file_len;

	string_file_len = ft_strlen(string_file);
	if ((i * (last_count + 1) + 1) <= string_file_len)
		return (0);
	return (count);
}

int	check_lines(char *charset, char *string_file, int lines)
{
	int	i;
	int	j;
	int	count;
	int	last_count;

	last_count = 0;
	i = 0;
	while (i < lines)
	{
		count = 0;
		j = 0;
		while (string_file[i * (last_count + 1) + j] != '\n')
		{
			if (!is_in_charset(string_file[i * (last_count + 1) + j], charset) 
				|| string_file[i * (last_count + 1) + j] == charset[2])
				return (0);
			count++;
			j++;
		}
		if (i != 0 && last_count != count)
			return (0);
		last_count = count;
		i++;
	}
	return (length_compare(string_file, count, i, last_count));
}

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (charset[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
