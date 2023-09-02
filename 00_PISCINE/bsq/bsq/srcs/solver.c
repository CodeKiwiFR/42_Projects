/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:47:55 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/29 13:58:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_min(int **matrix, int i, int j)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = matrix[i][j - 1];
	val2 = matrix[i - 1][j - 1];
	val3 = matrix[i - 1][j];
	if (val1 < val2)
	{
		if (val1 < val3)
			return (val1);
		else
			return (val3);
	}
	else
	{
		if (val2 < val3)
			return (val2);
		else
			return (val3);
	}
}

void	solve(t_matrix *matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix->line_cnt)
	{
		j = 0;
		while (j < matrix->col_cnt)
		{
			if (i != 0 && j != 0)
			{
				if ((matrix->matrix)[i][j] == -1)
					(matrix->matrix)[i][j] = get_min(matrix->matrix, i, j) + 1;
			}
			if (matrix->size < (matrix->matrix)[i][j])
			{
				matrix->size = (matrix->matrix)[i][j];
				matrix->x = i;
				matrix->y = j;
			}
			j++;
		}
		i++;
	}
}

void	apply_solution_to_map(t_map *map, t_matrix *matrix)
{
	int	i;
	int	j;
	int	i_size;
	int	j_size;

	i = matrix->x;
	i_size = matrix->size - 1;
	while (i_size >= 0)
	{
		j = matrix->y;
		j_size = matrix->size - 1;
		while (j_size >= 0)
		{
			(map->map)[i][j] = map->square;
			j--;
			j_size--;
		}
		i--;
		i_size--;
	}
}
