/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:50:14 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/30 05:06:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_maps(t_map *maps)
{
	int	i;

	if (maps == NULL)
		return ;
	i = 0;
	while (!(maps[i].map == NULL && maps[i].error == 0))
	{
		clean_str_array(maps[i].map, maps[i].line_cnt);
		i++;
	}
	free(maps);
}

void	clean_str_array(char **strs, int line_cnt)
{
	int	i;

	if (strs == NULL)
		return ;
	i = 0;
	while (i < line_cnt)
	{
		if (strs[i] == NULL)
			break ;
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	clean_int_array(int	**array, int line_cnt)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (i < line_cnt)
	{
		if (array[i] == NULL)
			break ;
		free(array[i]);
		i++;
	}
	free(array);
}
