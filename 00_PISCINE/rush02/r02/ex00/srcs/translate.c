/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:51:22 by mmorot            #+#    #+#             */
/*   Updated: 2023/08/27 17:38:27 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_current_order(int nb_len, t_translation *dict)
{
	int	i;

	if (nb_len <= 3)
		return (NULL);
	i = 1;
	while (dict[i].number != NULL)
	{
		if (dict[i].number_len > nb_len)
			return (dict[i - 1].translation);
		i++;
	}
	if (dict[i].number == NULL && dict[i - 1].number_len + 2 >= nb_len)
		return (dict[i - 1].translation);
	return (NULL);
}

int	eval_digits_to_handle(int nb_len)
{
	if (nb_len % 3 == 0)
		return (3);
	else
		return (nb_len % 3);
}

int	do_transl(char *nb, t_translation *dict, t_list **tr_result, int nb_len)
{
	char	*order;
	int		digits_to_handle;
	int		current_nb;
	int		res;

	order = get_current_order(nb_len, dict);
	if (order == NULL && nb_len > 3)
		return (-1);
	while (nb_len > 0)
	{
		digits_to_handle = eval_digits_to_handle(nb_len);
		current_nb = ft_atoi_n(nb, digits_to_handle);
		res = get_number_translation(current_nb, dict, tr_result);
		if (res == 0)
			return (0);
		if (order != NULL && current_nb != 0)
		{
			if (ft_push_back(tr_result, order) == 0)
				return (0);
		}
		nb += digits_to_handle;
		nb_len -= digits_to_handle;
		order = get_current_order(nb_len, dict);
	}
	return (1);
}

int	translate(char *number, t_translation *dict, t_list **tr_result)
{
	int		number_len;
	char	*res;

	number_len = ft_strlen(number);
	if (number_len == 1 && number[0] == '0')
	{
		res = find_in_dict(0, dict);
		if (!res)
			return (0);
		if (!ft_push_back(tr_result, res))
			return (0);
		return (1);
	}
	return (do_transl(number, dict, tr_result, number_len));
}
