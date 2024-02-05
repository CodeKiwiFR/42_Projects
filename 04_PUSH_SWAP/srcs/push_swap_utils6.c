/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:15:32 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 08:54:33 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_handle_printf_errors(t_ps_data *data, int returned)
{
	if (returned == -1)
	{
		data->clear(&data);
		exit(1);
	}
}
