/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:51:22 by mmorot            #+#    #+#             */
/*   Updated: 2023/08/27 18:09:45 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*find_in_dict(int nb, t_translation *dict)
{
	char	*nb_str;
	int		i;

	nb_str = ft_itoa_pos(nb);
	if (nb_str == NULL)
		return (NULL);
	i = 0;
	while (dict[i].number != NULL)
	{
		if (ft_strcmp(nb_str, dict[i].number) == 0)
		{
			free(nb_str);
			return (dict[i].translation);
		}
		i++;
	}
	free(nb_str);
	return (NULL);
}

int	get_hundreds(int nb, t_translation *dict, t_list **tr_result)
{
	int		current_digit;
	char	*translation;
	int		res;

	current_digit = nb / 100;
	if (current_digit != 0)
	{
		translation = find_in_dict(current_digit, dict);
		if (translation == NULL)
			return (0);
		res = ft_push_back(tr_result, translation);
		if (res == 0)
			return (0);
		translation = find_in_dict(100, dict);
		if (translation == NULL)
			return (0);
		res = ft_push_back(tr_result, translation);
		if (res == 0)
			return (0);
	}
	return (1);
}

int	get_tens(int nb, t_translation *dict, t_list **tr_result)
{
	int		current_digit;
	char	*translation;

	current_digit = nb / 10;
	if (current_digit != 0)
	{
		if (current_digit == 1)
		{
			translation = find_in_dict(nb, dict);
			if (translation == NULL)
				return (0);
			if (ft_push_back(tr_result, translation) == 0)
				return (0);
			return (2);
		}
		else
		{
			translation = find_in_dict(current_digit * 10, dict);
			if (translation == NULL)
				return (0);
			if (ft_push_back(tr_result, translation) == 0)
				return (0);
		}
	}
	return (1);
}

int	get_units(int nb, t_translation *dict, t_list **tr_result)
{
	char	*translation;

	translation = find_in_dict(nb, dict);
	if (translation == NULL)
		return (0);
	return (ft_push_back(tr_result, translation));
}

int	get_number_translation(int nb, t_translation *dict, t_list **tr_result)
{
	int	res;

	res = get_hundreds(nb, dict, tr_result);
	if (res == 0)
		return (0);
	nb %= 100;
	res = get_tens(nb, dict, tr_result);
	if (res == 0)
		return (0);
	nb %= 10;
	if (res != 2 && nb != 0)
	{
		res = get_units(nb, dict, tr_result);
		if (res == 0)
			return (0);
	}
	return (1);
}
