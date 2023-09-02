/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:17:53 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/27 22:31:29 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_line_elements(char **line_elements)
{
	int		len;
	char	*temp;

	len = 0;
	while (line_elements[len] != NULL)
		len++;
	if (len != 2)
		return (0);
	if (!clean_key(line_elements) || !is_valid_key(line_elements[0]))
		return (0);
	temp = ft_strtrim(line_elements[1]);
	if (!temp)
		return (0);
	free(line_elements[1]);
	line_elements[1] = temp;
	temp = clean_value(line_elements[1]);
	if (!temp)
		return (0);
	free(line_elements[1]);
	line_elements[1] = temp;
	return (1);
}

int	extract_data_from_line(char **line_elements, t_translation *dict_elem)
{
	if (check_line_elements(line_elements))
	{
		dict_elem->number = ft_strdup(line_elements[0]);
		dict_elem->translation = ft_strdup(line_elements[1]);
		dict_elem->number_len = ft_strlen(dict_elem->number);
		return (1);
	}
	return (0);
}

int	lines_to_dict(char **dict_lines, int nb_lines, t_translation **dict)
{
	int				i;
	int				j;
	char			**line_elements;

	*dict = (t_translation *)malloc((nb_lines + 1) * sizeof(t_translation));
	if (!(*dict))
		return (0);
	i = 0;
	j = 0;
	while (i < nb_lines)
	{
		line_elements = ft_split(dict_lines[i], ":");
		if (line_elements == NULL)
			return (0);
		if (extract_data_from_line(line_elements, (*dict) + j))
			j++;
		ft_free_tab(line_elements);
		i++;
	}
	(*dict)[j].number = NULL;
	(*dict)[j].translation = NULL;
	(*dict)[j].number_len = 0;
	return (1);
}

int	file_to_dict(char *file_content, t_translation **dict)
{
	char	**dict_lines;
	int		nb_lines;
	int		res;

	dict_lines = ft_split(file_content, "\n");
	if (dict_lines == NULL)
		return (0);
	nb_lines = ft_str_array_len(dict_lines);
	if (nb_lines < 41)
	{
		ft_free_tab(dict_lines);
		return (0);
	}
	res = lines_to_dict(dict_lines, nb_lines, dict);
	ft_free_tab(dict_lines);
	if (!res)
	{
		if (*dict != NULL)
		{
			clean_memory_dict(*dict);
			*dict = NULL;
		}
		return (0);
	}
	return (ft_check_dict(dict));
}
