/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:59:59 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/30 03:44:59 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	put_matrix_value(t_map *map, int **matrix, int i, int j)
{
	if ((map->map)[i][j] == map->obs)
		matrix[i][j] = 0;
	else
	{
		if (i == 0 || j == 0)
			matrix[i][j] = 1;
		else
			matrix[i][j] = -1;
	}
}

int	convert_map_to_matrix(t_map *map, int **matrix)
{
	char	error;
	int		i;
	int		j;

	error = 0;
	i = -1;
	while (++i < map->line_cnt)
	{
		matrix[i] = (int *)malloc(map->col_cnt * sizeof(int));
		if (!matrix[i])
		{
			error = 1;
			break ;
		}
		j = -1;
		while (++j < map->col_cnt)
			put_matrix_value(map, matrix, i, j);
	}
	if (error == 1)
	{
		clean_int_array(matrix, map->line_cnt);
		return (0);
	}
	return (1);
}

int	generate_matrix(t_map *map, t_matrix *s_matrix)
{
	int	**matrix_content;

	matrix_content = (int **)malloc(map->line_cnt * sizeof(int *));
	if (!matrix_content || !convert_map_to_matrix(map, matrix_content))
		return (0);
	s_matrix->line_cnt = map->line_cnt;
	s_matrix->col_cnt = map->col_cnt;
	s_matrix->matrix = matrix_content;
	s_matrix->x = 0;
	s_matrix->y = 0;
	s_matrix->size = (s_matrix->matrix)[0][0];
	return (1);
}
