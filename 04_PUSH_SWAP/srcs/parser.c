/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:48:17 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/09 21:57:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_number(char *str)
{
	if (str == NULL)
		return (false);
	if (*str == '-')
		str++;
	if (*str && !ft_isdigit(*str))
		return (false);
	while (*str && ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (true);
	return (false);
}

bool	parse_args(t_ps_data *data, int argc, char **argv)
{
	size_t	i;
	int		nb;

	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_number(argv[i]))
			return (false);
		nb = ft_atoi(argv[i]);
		if (!(data->push_a(data, nb)))
			return (false);
		i--;
	}
	return (true);
}
