/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_cleaner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:30:57 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/27 22:33:00 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	clean_key(char **key)
{
	char	*temp;

	temp = ft_strtrim(*key);
	if (temp == NULL)
		return (0);
	free(*key);
	*key = temp;
	temp = ft_atoa(*key);
	if (temp == NULL)
		return (0);
	free(*key);
	*key = temp;
	return (1);
}

char	*clean_value(char *value)
{
	char	*temp;
	char	**split;

	split = ft_split(value, " \t");
	if (split == NULL)
		return (0);
	temp = ft_strjoin(split);
	ft_free_tab(split);
	if (temp == NULL)
		return (NULL);
	return (temp);
}
