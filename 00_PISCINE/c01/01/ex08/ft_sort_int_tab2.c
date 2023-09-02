/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:15:49 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/11 08:29:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab2(int *tab, int size)
{
	int	index1;
	int	index2;
	int	temp;

	index1 = 1;
	while (index1 < size)
	{
		temp = tab[index1];
		index2 = index1;
		while (index2 > 0 && tab[index2 - 1] > temp)
		{
			tab[index2] = tab[index2 - 1];
			index2--;
		}
		tab[index2] = temp;
		index1++;
	}
}
