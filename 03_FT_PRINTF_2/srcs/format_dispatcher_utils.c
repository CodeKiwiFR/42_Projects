/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_dispatcher_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:49:41 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/07 10:58:45 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format_dispatcher(t_format_dispatcher dispatcher[NB_CONVERSION])
{
	dispatcher[0].flags = "di";
	dispatcher[0].f = NULL;
}
