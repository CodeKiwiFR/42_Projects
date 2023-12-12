/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_int_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/11 16:00:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fpf_int_manager(va_list args, t_input_format *input)
{
	int	nb;

	// TEMP
	if (input && 0)
		return (NULL);
	nb = va_arg(args, int);
	return (ft_itoa(nb));
}
