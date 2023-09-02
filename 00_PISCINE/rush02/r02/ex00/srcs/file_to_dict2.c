/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_dict2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:17:53 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/26 20:01:00 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	dict_contains_duplicates(t_translation *dict)
{
	int	i;
	int	j;
	int	dict_len;

	dict_len = 0;
	while (dict[dict_len].number != NULL)
		dict_len++;
	i = 0;
	while (i < dict_len)
	{
		j = i + 1;
		while (j < dict_len)
		{
			if (ft_strcmp(dict[i].number, dict[j].number) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	clean_memory_dict(t_translation *dict)
{
	int	i;

	i = 0;
	while (dict[i].number != NULL)
	{
		free(dict[i].number);
		free(dict[i].translation);
		i++;
	}
	free(dict);
}

void	dict_swap_elems(t_translation *elem1, t_translation *elem2)
{
	int		temp_nb;
	char	*temp_str;

	temp_str = elem1->number;
	elem1->number = elem2->number;
	elem2->number = temp_str;
	temp_str = elem1->translation;
	elem1->translation = elem2->translation;
	elem2->translation = temp_str;
	temp_nb = elem1->number_len;
	elem1->number_len = elem2->number_len;
	elem2->number_len = temp_nb;
}

void	dict_sort(t_translation *dict)
{
	int		i;
	int		j;

	i = 0;
	while (dict[i].number != NULL)
	{
		j = i + 1;
		while (dict[j].number != NULL)
		{
			if (
				dict[i].number_len > dict[j].number_len 
				|| (
					dict[i].number_len == dict[j].number_len
					&& ft_strcmp(dict[i].number, dict[j].number) > 0
				)
			)
				dict_swap_elems(dict + i, dict + j);
			j++;
		}
		i++;
	}
}
