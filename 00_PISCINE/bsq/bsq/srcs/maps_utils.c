/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:39:02 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/30 18:07:56 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	init_map_array(t_map **maps, int array_size)
{
	t_map	*array;
	int		i;

	array = (t_map *)malloc((array_size + 1) * sizeof(t_map));
	if (!array)
		return (0);
	i = 0;
	while (i <= array_size)
	{
		array[i].map = NULL;
		array[i].error = 0;
		i++;
	}
	*maps = array;
	return (1);
}

void	display_map(t_map *map)
{
	int	i;

	if (map->error == 1)
	{
		ft_putstr("map error\n");
		return ;
	}
	i = 0;
	while (i < map->line_cnt)
	{
		ft_putstr_len((map->map)[i], map->col_cnt);
		ft_putchar('\n');
		i++;
	}
}

void	display_all_maps(t_map *maps)
{
	int	i;
	int	count;

	count = 0;
	while (!(maps[count].map == NULL && maps[count].error == 0))
		count++;
	i = 0;
	while (!(maps[i].map == NULL && maps[i].error == 0))
	{
		display_map(maps + i);
		if (count > 1)
			ft_putchar('\n');
		i++;
	}
}

int	fill_map(t_map *s_map, char *str)
{
	char	**map;
	char	*line;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc((s_map->line_cnt) * sizeof(char *));
	if (!map)
		return (0);
	s_map->map = map;
	while (i < s_map->line_cnt)
	{
		line = (char *)malloc((s_map->col_cnt) * sizeof(char));
		if (!line)
			return (0);
		j = 0;
		while (j < s_map->col_cnt)
		{
			line[j] = str[i * (s_map->col_cnt) + j];
			j++;
		}
		map[i] = line; 
		i++;
	}
	return (1);
}
