/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_string_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 16:41:17 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fpf_string_manager(va_list args, t_input_format *input)
{
	char	*str;
	char	*res;

	if (input && 0)
		return (NULL);
	str = va_arg(args, char *);
	if (str == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(str);
	return (res);
}
