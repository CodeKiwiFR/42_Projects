/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:47:07 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/30 20:14:58 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_valid_char(char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] < 32 || charset[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	long	i;
	int		count;

	count = 0;
	i = 0;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			count ++;
		str++;
	}
	if (*str == 32 || (*str > 8 && *str < 14))
		return (0);
	while (*str > 47 && *str < 58)
	{
		i = i * 10 + *str - '0';
		str++;
	}
	if (count % 2 == 1)
		i *= -1;
	return (i);
}

void	write_map(t_map	s_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_map.line_cnt)
	{
		j = 0;
		while (j <= s_map.col_cnt)
		{
			write(1, &s_map.map[i][j], 1);
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

char	*rmv_nl(char *str)
{
	char	*s;
	int		i;
	int		j;
	int		size;

	size = 0;
	while (str[size])
		size++;
	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			s[j++] = str[i];
		i++;
	}
	s[j] = 0;
	return (s);
}
