/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:24:37 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/19 19:03:57 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
void	ft_extract_input_data(char grid[6][6], char *input);
void	ft_initialize_content(char grid[6][6]);
void	ft_display_grid(char grid[6][6]);
int		ft_find_solution(char grid[6][6], int line, int col);
int		ft_check_input(char *input);

int	main(int argc, char **argv)
{
	char	*input;
	char	grid[6][6];
	int		found_solution;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	input = argv[1];
	if (!ft_check_input(input))
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_initialize_content(grid);
	ft_extract_input_data(grid, input);
	found_solution = ft_find_solution(grid, 1, 1);
	if (!found_solution)
		ft_putstr("Error\n");
	else
		ft_display_grid(grid);
	return (0);
}
