/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:50:28 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/25 09:14:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	first_way;
	int	other_way;

	i = 0;
	first_way = 1;
	other_way = 1;
	while (i < length - 1)
	{
		if (first_way == 1 && f(tab[i], tab[i + 1]) > 0)
			first_way = 0;
		if (other_way == 1 && f(tab[i], tab[i + 1]) < 0)
			other_way = 0;
		i++;
	}
	if (first_way == 1 || other_way == 1)
		return (1);
	return (0);
}
