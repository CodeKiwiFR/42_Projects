/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:48:17 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/11 15:40:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0' || !ft_isdigit(*str))
		return (false);
	while (*str && ft_isdigit(*str))
		str++;
	while (ft_isspace(*str))
		str++;
	if (*str == '\0')
		return (true);
	return (false);
}

bool	parse_args(t_ps_data *data, int argc, char **argv)
{
	size_t	i;

	if (data == NULL || argv == NULL)
		return (false);
	i = argc - 1;
	while (true)
	{
		if (!is_valid_number(argv[i]))
			return (false);
		if (!(data->push_a(data, ft_atoi(argv[i]))))
			return (false);
		if (i == 0)
			break ;
		i--;
	}
	return (true);
}

bool	parse_one_arg(t_ps_data *data, char *str)
{
	char	*curr_nb_end;

	if (str == NULL || data == NULL)
		return (false);
	while (*str != '\0')
	{
		while (ft_isspace(*str))
			str++;
		curr_nb_end = str;
		if (*curr_nb_end == '+' || *curr_nb_end == '-')
			curr_nb_end++;
		if (*curr_nb_end == '\0' || !ft_isdigit(*curr_nb_end))
			return (false);
		while (ft_isdigit(*curr_nb_end))
			curr_nb_end++;
		if (*curr_nb_end != '\0' && !ft_isspace(*curr_nb_end))
			return (false);
		if (!(data->push_a(data, ft_atoi(str))))
			return (false);
		while (ft_isspace(*curr_nb_end))
			curr_nb_end++;
		str = curr_nb_end;
	}
	return (true);
}
