/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:36:11 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/13 02:13:57 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	choix_tab(int i, int j, int x, int y)
{
	char	r;

	if (i == 0 && (j == 0 || j == x - 1))
	{
		r = 'A';
		return (r);
	}
	if (i == y - 1 && (j == 0 || j == x - 1))
	{
		r = 'C';
		return (r);
	}
	else
	{
		r = 'B';
		return (r);
	}
}

void	rush(int x, int y)
{
	char	r;
	int		i;
	int		j;

	if (x < 1 || y < 1)
		return ;
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			r = choix_tab(i, j, x, y);
			if ((i < (y - 1) && i > 0) && (j < (x - 1) && (j > 0)))
				ft_putchar(' ');
			else
				ft_putchar(r);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
