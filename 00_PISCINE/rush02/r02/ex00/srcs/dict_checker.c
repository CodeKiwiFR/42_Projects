/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:50:50 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/27 00:10:58 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_required_keys(t_translation *dict)
{
	char	*required_str;
	char	**required_array;
	int		i;

	required_str = 
		"0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,\
		80,90,100,1000,1000000,1000000000,1000000000000,\
		1000000000000000,1000000000000000000,1000000000000000000000,\
		1000000000000000000000000,1000000000000000000000000000,\
		1000000000000000000000000000000,1000000000000000000000000000000000,\
		1000000000000000000000000000000000000";
	required_array = ft_split(required_str, ",\n\r\f\t\v ");
	if (required_array == NULL)
		return (0);
	i = 0;
	while (i < 41)
	{
		if (ft_strcmp(dict[i].number, required_array[i]) != 0)
		{
			ft_free_tab(required_array);
			return (0);
		}
		i++;
	}
	ft_free_tab(required_array);
	return (1);
}

int	ft_get_dict_len(t_translation *dict)
{
	int	count;

	count = 0;
	while (dict[count].number != NULL)
		count++;
	return (count);
}

int	ft_check_dict(t_translation **dict)
{
	int	dict_len;

	dict_len = ft_get_dict_len(*dict);
	if (*dict == NULL)
		return (0);
	if (dict_len < 41 || dict_contains_duplicates(*dict))
	{
		clean_memory_dict(*dict);
		*dict = NULL;
		return (0);
	}
	dict_sort(*dict);
	if (!ft_check_required_keys(*dict))
	{
		clean_memory_dict(*dict);
		*dict = NULL;
		return (0);
	}
	return (1);
}
