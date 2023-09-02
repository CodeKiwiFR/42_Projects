/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:13:27 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 18:48:56 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>            
#include <stdio.h>

int	ft_count_if(char **tab, int length, int (*f)(char*));

int	ft_starts_with_p(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == 'p' || *str == 'P')
		return (1);
	return (0);
}

int	main(void)
{
	char	*tab[4];
	char	*tab2[4];

	tab[0] = "No";
	tab[1] = "Yes";
	tab[2] = "Why";
	tab[3] = "Sorry";
	tab2[0] = "Poo";
	tab2[1] = "Poor";
	tab2[2] = "Why";
	tab2[3] = "Pickles";
	printf("Tab  nb of p words: %d\n", ft_count_if(tab, 4, &ft_starts_with_p));
	printf("Tab2 nb of p words: %d\n", ft_count_if(tab2, 4, &ft_starts_with_p));
	return (0);
}
