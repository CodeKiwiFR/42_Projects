/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:35:21 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/17 11:18:59 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_diagonals(char grid[10][10], int i, int j)
{
	int	i_chk;
	int	j_chk;

	i_chk = i;
	j_chk = j;
	while (i_chk > 0 && j_chk > 0)
	{
		i_chk--;
		j_chk--;
	}
	while (i_chk <= i - 1 && j_chk <= j - 1)
		if (grid[i_chk++][j_chk++] == 1)
			return (0);
	i_chk = i;
	j_chk = j;
	while (i_chk > 0 && j_chk < 9)
	{
		i_chk--;
		j_chk++;
	}
	while (i_chk <= i - 1 && j_chk >= j + 1)
		if (grid[i_chk++][j_chk--] == 1)
			return (0);
	return (1);
}

int	ft_check_grid(char grid[10][10], int i, int j)
{
	int	i_browser;

	i_browser = 0;
	while (i_browser < 10)
	{
		if (i_browser != i && grid[i_browser][j] == 1)
			return (0);
		i_browser++;
	}
	if (!ft_check_diagonals(grid, i, j))
		return (0);
	return (1);
}

void	ft_print_grid(char grid[10][10])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (grid[i][j] == 1)
			{
				c = (char)j + '0';
				write(1, &c, 1);
				break ;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	ft_place_queen_at_position(char grid[10][10], int line, int col)
{
	int	cpt;

	cpt = 0;
	if (line >= 10)
	{
		ft_print_grid(grid);
		return (1);
	}
	else if (col >= 10)
		return (0);
	else
	{
		grid[line][col] = 1;
		if (ft_check_grid(grid, line, col))
			cpt += ft_place_queen_at_position(grid, line + 1, 0);
		grid[line][col] = 0;
		cpt += ft_place_queen_at_position(grid, line, col + 1);
	}
	return (cpt);
}

int	ft_ten_queens_puzzle(void)
{
	char	grid[10][10];
	int		i;
	int		j;
	int		cpt;

	i = 0;
	cpt = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ft_place_queen_at_position(grid, 0, 0));
}
