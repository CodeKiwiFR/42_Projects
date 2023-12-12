/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_dispatcher_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:49:41 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/12 17:59:57 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format_dispatch(t_format_dispatch dispatch[NB_CONV])
{
	dispatch[0].flags = "di";
	dispatch[0].f = fpf_int_manager;
	dispatch[1].flags = "s";
	dispatch[1].f = fpf_string_manager;
	dispatch[2].flags = "c";
	dispatch[2].f = fpf_char_manager;
	dispatch[3].flags = "%";
	dispatch[3].f = fpf_percent_manager;
	dispatch[4].flags = "u";
	dispatch[4].f = fpf_uint_manager;
}

char	*(*dispatch_get_func(t_format_dispatch dispatch[NB_CONV], char flag))(
	va_list args,
	t_input_format *input
)
{
	size_t	i;

	if (dispatch == NULL)
		return (NULL);
	i = 0;
	while (i < NB_CONV)
	{
		if (ft_strchr(dispatch[i].flags, flag) != NULL)
			return (dispatch[i].f);
		i++;
	}
	return (NULL);
}
