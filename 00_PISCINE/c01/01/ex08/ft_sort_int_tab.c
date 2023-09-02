/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:15:49 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/10 19:19:45 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	index1;
	int	index2;
	int	temp;

	index1 = 0;
	while (index1 < size)
	{
		index2 = index1 + 1;
		while (index2 < size)
		{
			if (tab[index1] > tab[index2])
			{
				temp = tab[index1];
				tab[index1] = tab[index2];
				tab[index2] = temp;
			}
			index2++;
		}
		index1++;
	}
}
