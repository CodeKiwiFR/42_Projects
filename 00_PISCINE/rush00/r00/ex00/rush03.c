/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 02:17:27 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/13 18:03:48 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	ft_determine_char(int col, int line, int nb_cols, int nb_lines)
{
	if (line == 0)
	{
		if (col == 0)
			return ('A');
		else if (col == nb_cols - 1)
			return ('C');
		else
			return ('B');
	}
	else if (line == nb_lines - 1)
	{
		if (col == 0)
			return ('A');
		else if (col == nb_cols - 1)
			return ('C');
		else
			return ('B');
	}
	else
	{
		if (col == 0 || col == nb_cols - 1)
			return ('B');
		else
			return (' ');
	}
}

void	rush(int x, int y)
{
	int	line;
	int	col;
	int	nb_cols;
	int	nb_lines;

	nb_cols = x;
	nb_lines = y;
	if (nb_cols < 1 || nb_lines < 1)
		return ;
	line = 0;
	while (line < nb_lines)
	{
		col = 0;
		while (col < nb_cols)
		{
			ft_putchar(ft_determine_char(col, line, nb_cols, nb_lines));
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}
