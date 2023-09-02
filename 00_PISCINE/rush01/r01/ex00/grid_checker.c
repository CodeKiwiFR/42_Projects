/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:42:37 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/19 19:33:55 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_up_visible(char grid[6][6], int line, int col)
{
	int	up_expected;
	int	i;
	int	j;
	int	cpt;

	up_expected = grid[0][col];
	i = 2;
	cpt = 1;
	while (i <= line && grid[i][col] != 0)
	{
		j = 0;
		while (++j < i)
		{
			if (grid[j][col] > grid[i][col])
				break ;
		}
		if (i == j)
			cpt++;
		i++;
	}
	if (cpt > up_expected || (cpt < up_expected && line == 4))
		return (0);
	return (1);
}

int	ft_check_down_visible(char grid[6][6], int line, int col)
{
	int	down_expected;
	int	i;
	int	j;
	int	cpt;

	if (line < 4)
		return (1);
	down_expected = grid[5][col];
	i = 3;
	cpt = 1;
	while (i >= 1)
	{
		j = 5;
		while (--j > i)
		{
			if (grid[j][col] > grid[i][col])
				break ;
		}
		if (i == j)
			cpt++;
		i--;
	}
	if (cpt != down_expected)
		return (0);
	return (1);
}

int	ft_check_left_visible(char grid[6][6], int line, int col)
{
	int	left_expected;
	int	i;
	int	j;
	int	cpt;

	left_expected = grid[line][0];
	i = 2;
	cpt = 1;
	while (i <= col && grid[line][i] != 0)
	{
		j = 0;
		while (++j < i)
		{
			if (grid[line][j] > grid[line][i])
				break ;
		}
		if (i == j)
			cpt++;
		i++;
	}
	if (cpt > left_expected || (cpt < left_expected && col == 4))
		return (0);
	return (1);
}

int	ft_check_right_visible(char grid[6][6], int line, int col)
{
	int	right_expected;
	int	i;
	int	j;
	int	cpt;

	if (col < 4)
		return (1);
	right_expected = grid[line][5];
	i = 3;
	cpt = 1;
	while (i >= 1)
	{
		j = 5;
		while (--j > i)
		{
			if (grid[line][j] > grid[line][i])
				break ;
		}
		if (i == j)
			cpt++;
		i--;
	}
	if (cpt != right_expected)
		return (0);
	return (1);
}

int	ft_check_row_col(char grid[6][6], int line, int col)
{
	int	i;

	i = line - 1;
	while (i > 0)
	{
		if (grid[line][col] == grid[i][col])
			return (0);
		i--;
	}
	i = col - 1;
	while (i > 0)
	{
		if (grid[line][col] == grid[line][i])
			return (0);
		i--;
	}
	return (1);
}
