/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:09:09 by pbigot            #+#    #+#             */
/*   Updated: 2023/08/30 12:16:20 by pbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	build_maps_from_data(t_map **maps, int argc, char **argv)
{
	int	res;

	if (argc == 1)
	{
		if (!init_map_array(maps, 1))
			return (0);
		res = read_from_stdin(maps[0]);
		if (!res)
		{
			free_maps(*maps);
			return (0);
		}
		return (1);
	}
	else
	{
		*maps = get_map_struct(argc, argv);
		return (1);
	}
}

int	solve_maps(t_map *maps)
{
	int			i;
	t_matrix	matrix;

	i = 0;
	while (!(maps[i].map == NULL && maps[i].error == 0))
	{
		if (maps[i].error == 1)
		{
			i++;
			continue ;
		}
		if (!generate_matrix(maps + i, &matrix))
			return (0);
		solve(&matrix);
		apply_solution_to_map(maps + i, &matrix);
		clean_int_array(matrix.matrix, matrix.line_cnt);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*maps;

	maps = NULL;
	if (!build_maps_from_data(&maps, argc, argv))
		return (1);
	if (!solve_maps(maps))
	{
		free_maps(maps);
		return (1);
	}
	display_all_maps(maps);
	free_maps(maps);
	return (0);
}
