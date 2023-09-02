/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main07.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:13:27 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/25 12:13:34 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>            
#include <stdio.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			return ((int)(s1[index] - s2[index])); 
		index++;
	}
	return ((int)(s1[index] - s2[index])); 
}

int	ft_compare_lens(char *s1, char *s2)
{
	int	len_s1;
	int	len_s2;

	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	if (len_s1 > len_s2)
		return (1);
	else if (len_s1 == len_s2)
		return (0);
	else
		return (-1);
}

void	ft_disp_array(char **array)
{
	int	i;

	i = 0;
	printf("[");
	while (array[i] != 0)
	{
		printf("\"%s\"", array[i]);
		if (array[i + 1] != 0)
			printf(", ");
		i++;
	}
	printf("]\n");
}

int	main(void)
{
	char *tab[19];

	tab[0] = "F";
	tab[1] = "AoJDjpXb";
	tab[2] = "6ik";
	tab[3] = "g0jx6A9mzOoS";
	tab[4] = "hV6wt";
	tab[5] = "FJgVWsj";
	tab[6] = "Ii9ZGTNoLb";
	tab[7] = "EWpm6fFbKTn";
	tab[8] = "Llo";
	tab[9] = "Bz";
	tab[10] = "JLf";
	tab[11] = "mKnzUS6";
	tab[12] = "S9YGrosR";
	tab[13] = "SNW9ojIay8f";
	tab[14] = "VKa";
	tab[15] = "YjShF1fM";
	tab[16] = "C96EDpn";
	tab[17] = "KUf4";
	tab[18] = 0;

	ft_disp_array(tab);
	ft_advanced_sort_string_tab(tab, &ft_compare_lens);
	ft_disp_array(tab);
	printf("\n----------\n\n");
	return (0);
}

/*
int	main(void)
{
	char*	tab[5];
	char*	tab2[1];
	char*	tab3[2];

	tab[0] = "abc";
	tab[1] = "a";
	tab[2] = "0123";
	tab[3] = "def";
	tab[4] = 0;
	tab2[0] = 0;
	tab3[0] = "bonjour";
	tab3[1] = 0;
	ft_disp_array(tab);
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	ft_disp_array(tab);
	printf("\n----------\n\n");
	ft_disp_array(tab2);
	ft_advanced_sort_string_tab(tab2, &ft_strcmp);
	ft_disp_array(tab2);
	printf("\n----------\n\n");
	ft_disp_array(tab3);
	ft_advanced_sort_string_tab(tab3, &ft_strcmp);
	ft_disp_array(tab3);
	printf("\n----------\n\n");
	ft_advanced_sort_string_tab(0, &ft_strcmp);
	printf("\n----------\n\n");
	ft_advanced_sort_string_tab(tab, 0);
	printf("\n----------\n\n");
	ft_disp_array(tab);
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	ft_disp_array(tab);

	return (0);
}
*/
