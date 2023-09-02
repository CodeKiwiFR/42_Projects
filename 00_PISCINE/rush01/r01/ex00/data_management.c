/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:38:01 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/19 01:38:22 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_extract_input_data(char grid[6][6], char *input)
{
	int	i;
	int	grid_index;

	i = 0;
	grid_index = 1;
	while (i < 31)
	{
		if (i < 8)
			grid[0][grid_index] = input[i] - '0';
		else if (i < 16)
			grid[5][grid_index] = input[i] - '0';
		else if (i < 24)
			grid[grid_index][0] = input[i] - '0';
		else
			grid[grid_index][5] = input[i] - '0';
		if (grid_index == 4)
			grid_index = 1;
		else
			grid_index++;
		i += 2;
	}
}

void	ft_initialize_content(char grid[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}
