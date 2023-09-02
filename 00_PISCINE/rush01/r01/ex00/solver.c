/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:28:28 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/19 16:45:27 by vcarbon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_up_visible(char grid[6][6], int line, int col);
int	ft_check_down_visible(char grid[6][6], int line, int col);
int	ft_check_left_visible(char grid[6][6], int line, int col);
int	ft_check_right_visible(char grid[6][6], int line, int col);
int	ft_check_row_col(char grid[6][6], int line, int col);

int	ft_is_valid(char grid[6][6], int line, int col)
{
	if (
		!ft_check_row_col(grid, line, col)
		|| !ft_check_up_visible(grid, line, col)
		|| !ft_check_down_visible(grid, line, col)
		|| !ft_check_left_visible(grid, line, col)
		|| !ft_check_right_visible(grid, line, col)
	)
		return (0);
	return (1);
}

int	ft_find_solution(char grid[6][6], int line, int col)
{
	if (line > 4)
		return (1);
	if (col > 4)
	{
		if (ft_find_solution(grid, line + 1, 1))
			return (1);
		else
			return (0);
	}
	grid[line][col] = grid[line][col] + 1;
	if (grid[line][col] > 4)
	{
		grid[line][col] = 0;
		return (0);
	}
	if (ft_is_valid(grid, line, col) && ft_find_solution(grid, line, col + 1))
		return (1);
	else if (ft_find_solution(grid, line, col))
		return (1);
	return (0);
}
