/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:40:43 by pbigot            #+#    #+#             */
/*   Updated: 2023/08/30 19:06:38 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	return_and_free(t_map *s_map, char *str, char *charset)
{
	if (str != NULL)
		free(str);
	if (charset != NULL)
		free(charset);
	s_map->error = 1;
	return ;
}

void	set_map_elements(t_map *s_map, char *charset, char *str)
{
	int	returned;

	s_map->free = charset[0];
	s_map->obs = charset[1];
	s_map->square = charset[2];
	returned = fill_map(s_map, str);
	if (!returned)
		s_map->error = 1;
}

void	fill_struct(t_map *s_map, char *str)
{
	char	*charset;

	if (ft_strlen(str) <= 1)
		return (return_and_free(s_map, NULL, NULL));
	s_map->error = '0';
	charset = get_charset(str);
	if (!charset || !check_characters(charset))
		return (return_and_free(s_map, charset, NULL));
	s_map->line_cnt = get_line_cnt(str);
	if (s_map->line_cnt < 1)
		return (return_and_free(s_map, NULL, charset));
	while (*str != '\n')
		str++;
	str++;
	s_map->col_cnt = check_lines(charset, str, s_map->line_cnt);
	str = rmv_nl(str);
	if (
		!str || s_map->col_cnt == 0
		|| !check_line_nbr(s_map->line_cnt, s_map->col_cnt, str)
	)
		return (return_and_free(s_map, str, charset));
	set_map_elements(s_map, charset, str);
	free(str);
	free(charset);
	return ;
}

t_map	*get_map_struct(int argc, char **argv)
{
	t_map	*s_map;
	int		i;
	char	*str;

	i = 0;
	init_map_array(&s_map, argc - 1);
	if (!s_map)
		return (0);
	while (i < argc - 1)
	{
		str = get_file_data(argv[i + 1]);
		if (str == NULL)
		{
			s_map[i].error = 1;
			i++;
			continue ;
		}
		fill_struct(s_map + i, str);
		free(str);
		i++;
	}
	s_map[i].map = NULL;
	s_map[i].error = 0;
	return (s_map);
}
